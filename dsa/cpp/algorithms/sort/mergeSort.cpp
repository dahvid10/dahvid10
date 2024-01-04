#include <iostream>
#include <vector>

using namespace std;

vector<int> merge_sort(vector<int> &v) {
    // make merge helper fn
    // return v if its length <= 1
    if (v.size() <= 1) {
        return v;
    }
    // get mid index
    int midInd = v.size()/2;
    // get left partition
    vector<int> left = vector<int>(v.begin(), v.begin()+midInd);
    // get right partition
    vector<int> right = vector<int>(v.begin()+midInd,v.end());
    // call helper fn on left partition
    merge_sort(left);
    // call helper fn on right partition
    merge_sort(right);
    // compare values from left and right partitions to sort
    int leftInd, rightInd, finalInd;
    leftInd = rightInd = finalInd = 0;

    while ( (leftInd < left.size()) && (rightInd < right.size()) ) {
        if (left[leftInd] < right[rightInd]) {
            v[finalInd] = left[leftInd];
            leftInd += 1;
        } else {
            v[finalInd] = right[rightInd];
            rightInd += 1;
        }
        finalInd += 1;
    }
    // empty contents of remaining partition into final arr
    while (leftInd < left.size()) {
        v[finalInd] = left[leftInd];
        leftInd += 1;
        finalInd += 1;
    }
    while (rightInd < right.size()) {
        v[finalInd] = right[rightInd];
        rightInd += 1;
        finalInd += 1;
    }

    // return sorted arr
    return v;
}

int main_merge()
{
    vector<int> sample_v = {6, 34, 24, 32, 23};
    vector<int> sorted_v = merge_sort(sample_v);
    for (int num : sorted_v)
    {
        cout << num << " " << endl;
    }
    return 0;
}

