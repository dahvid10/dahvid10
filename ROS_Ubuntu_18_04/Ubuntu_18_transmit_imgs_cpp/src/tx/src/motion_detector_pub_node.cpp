//Description: This code captures video and detects motion.  

// Motion detection is achieved with the following sequence:
// 1. capture 'first frame',
// 2. find absolute difference between first frame and subsequent frames
// 3. find and draw contours of absolute differences (if applicable) in subsequent frames
// 4. calculate the area of each contour.
// 5. if the area is significant (>1000 pixels^2, or any desired sensitivity value), then there was motion.

//Link: https://gist.github.com/six519/6d2beee53038ebe8abd98063abfdad86

#include <opencv2/opencv.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/core.hpp>
//#include <opencv2/video/tracking.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
// #include <Windows.h>
#include <stdlib.h>
#include <chrono>

#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <ros/ros.h>
#include <sensor_msgs/image_encodings.h>

using namespace cv;
using namespace std;
using namespace chrono;

int main(int argc, char** argv) {
    // initialize pub node
    ros::init(argc, argv, "motion_detector_pub_node");
    ros::NodeHandle nh;  // Default handler for nodes in ROS

    //select camera 0 to receive imgs from
    VideoCapture camera(0);
    if (!camera.isOpened()) {
      ROS_ERROR_STREAM("Failed to open camera!");
      ros::shutdown();
    }
    
     //initialize n-dimensional arrays to hold images
    Mat frame, gray, frameDelta, thresh, firstFrame;
    sensor_msgs::ImagePtr msg;

    //create vector of vectors to capture contours (return value of findContours)
    vector<vector<Point>> contours;

    // Image_transport is responsible for publishing and subscribing to Images
    image_transport::ImageTransport it(nh);
     
    // Publish to the /camera topic
    image_transport::Publisher pub_frame = it.advertise("camera", 1);

    //set window size of camera feed
    camera.set(3, 512);
    camera.set(4, 288);

    //sleep for 5 ms, then capture img frame
    // Sleep(5);
    camera.read(frame);

    // convert to grayscale and capture first frame
    cvtColor(frame, firstFrame, COLOR_BGR2GRAY);
    GaussianBlur(firstFrame, firstFrame, Size(21, 21), 0);

    //start timer
    auto start = high_resolution_clock::now();

    // run loop at a rate of 10 Hz
    ros::Rate loop_rate(10);

    //continuously capture new frames and detect motion
    while (nh.ok() && camera.read(frame)) {
        // Check if grabbed frame has content
        if (frame.empty()) {
            ROS_ERROR_STREAM("Failed to capture image!");
            ros::shutdown();
        }

        // convert new frame to grayscale
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        //apply gaussian blur to grayscale frame, this helps to filter out noise
        GaussianBlur(gray, gray, Size(21, 21), 0);

        // compute per-element absolute difference between the first frame and current frame
        absdiff(firstFrame, gray, frameDelta);

        //apply fixed-level threshold, 25, to each array element in 'frameDelta'
        //set values of frameDelta between 25 and 255 and assign to 'thresh'
        threshold(frameDelta, thresh, 25, 255, THRESH_BINARY);
        
        //increase size of foreground object 2 times using structuring element 'Mat()'
        dilate(thresh, thresh, Mat(), Point(-1, -1), 2);
        
        //find contours in threshold img
        findContours(thresh, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        //draw contours
        Mat frame_contours = frame.clone();
        drawContours(frame_contours, contours, -1, Scalar(0, 255, 0), 2);

        //calculate area of each contour
        //if contour's area is significant (>5000 pixels^2), alert 'motion detected'
        for (int i = 0; i < contours.size(); i++) {
            // adjust this value to control sensitivity of motion detector
            if (contourArea(contours[i]) < 1000) {
                continue;
            }
            putText(frame, "Motion Detected", Point(10, 20), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 0, 255), 2);
            putText(frame_contours, "Motion Detected", Point(10, 20), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 0, 255), 2);
        }

        // Convert image from cv::Mat (OpenCV) type to sensor_msgs/Image (ROS) type and publish
        msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();
        msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame_contours).toImageMsg(); //uncomment to see contours on camera feed
        pub_frame.publish(msg);

        //show frames
        // imshow("Camera", frame);
        // imshow("Contours", frame_contours);

        //capture current time
        auto checkTime = high_resolution_clock::now();
        
        //print timer
        //cout << duration_cast<seconds>(checkTime - start).count() << endl;
             
        //set new frame every 5 seconds
        if (duration_cast<seconds>(checkTime - start).count() > 4) {
            camera.read(frame);
            cvtColor(frame, firstFrame, COLOR_BGR2GRAY);
            GaussianBlur(firstFrame, firstFrame, Size(21, 21), 0);
            start = high_resolution_clock::now();
        }

        // //exit if 'escape' key is pressed
        // if (waitKey(1) == 27) {
        //     break;
        // };

        // wait for at least 1 ms, this is to allow camera feed to loop, otherwise it would show the same frame forever
        waitKey(1);

        ros::spinOnce();
        loop_rate.sleep();
    }

    // Shutdown the camera
    camera.release();

    return 0;
}