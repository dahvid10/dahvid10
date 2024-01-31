#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

class Employee
{
    private:
        // Private attribute
        int salary;

    public:
        // Setter
        void setSalary(int s)
        {
            salary = s;
        }
        // Getter
        int getSalary()
        {
            return salary;
        }
};

// 
// Base class
class Vehicle
{
public:
    string brand = "Ford";
    void honk()
    {
        cout << "Tuut, tuut! \n";
    }
};

// Derived class
class Car : public Vehicle
{
public:
    string model = "Mustang";
};

// POLYMORPHISM
// Base class
class Animal
{
public:
    void animalSound()
    {
        cout << "The animal makes a sound \n";
    }
};

// Derived class
class Pig : public Animal
{
public:
    void animalSound()
    {
        cout << "The pig says: wee wee \n";
    }
};

// Derived class
class Dog : public Animal
{
public:
    void animalSound()
    {
        cout << "The dog says: bow wow \n";
    }
};

int main() {
    // cout << "Hello World!\n";

    // int num = 15;
    // cout << num << endl;

    // int x, y, z;
    // x = y = z = 50;
    // cout << x + y + z << endl;

    // cout << "Enter a number to replace x: ";
    // cin >> x;
    // cout << x << endl;

    // string text = "new text";
    // cout << text;

    // cout << sqrt(144) << endl;
    // cout << round(4.4) << endl;
    // cout << log(4) << endl;

    // int day;
    // char retry;

    // do {
    //     cout << "Enter number of day: ";
    //     cin >> day;
    //     switch (day)
    //     {
    //     case 6:
    //         cout << "Today is Saturday";
    //         break;
    //     case 7:
    //         cout << "Today is Sunday";
    //         break;
    //     default:
    //         cout << "Looking forward to the Weekend";
    //     }
    //     cout << "\nWould you like to update the number of day? (y/n)" << endl;
    //     cin >> retry;
    // } while (retry == 'y');

    // int myNumbers[5] = {10, 20, 30, 40, 50};
    // for (int i=0; i < sizeof(myNumbers)/sizeof(int); i++) {
    //     cout << myNumbers[i] << endl;
    // }

    // for (int i : myNumbers){
    //     cout << i << "\n";
    // }

    // vector<int> arr;
    // arr.push_back(1);
    // arr.push_back(2);
    // arr.pop_back();

    // for (int i : arr) {
    //     cout << i << endl;
    // }

    // struct car{
    //     string brand;
    //     string model;
    //     int year;
    // };

    // car car1;
    // car1.brand = "Honda";
    // car1.model = "Accord";
    // car1.year = 2013;

    // car car2; 
    // car2.brand = "Honda";
    // car2.model = "Civic";
    // car2.year = 2016;

    // cout << "That car is a " << car1.year << " " << car1.brand << " " << car1.model << endl;
    // cout << "That car is a " << car2.year << " " << car2.brand << " " << car2.model << endl;

    // string food = "Pizza";
    // string &meal = food;
    // string* ptr = &food;

    // cout << food << "\n"; // Outputs Pizza
    // cout << meal << "\n"; // Outputs Pizza

    // cout << &food << endl; // Outputs memory address
    // cout << ptr << endl;
    // cout << *ptr << endl;
    // // Change the value of the pointer
    // *ptr = "Hamburger";

    // // Output the new value of the pointer (Hamburger)
    // cout << *ptr << "\n";

    // // Output the new value of the food variable (Hamburger)
    // cout << food << "\n";

    // ENCAPSULATION
    // Employee myObj;
    // myObj.setSalary(50000);
    // cout << myObj.getSalary();

    // INHERITANCE
    // Car myCar;
    // myCar.honk();
    // cout << myCar.brand + " " + myCar.model;

    // Create and open a text file
    // ofstream MyFile("filename.txt");
    fstream MyFile("filename.txt");

    // Write to the file
    while(MyFile.is_open()) {
        MyFile << "Files can be tricky, but it is fun enough!";
        // Close the file
        MyFile.close();
    }

    string myText;

    // Read from the text file
    ifstream MyReadFile("filename.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText)) {
        // Output the text from the file
        cout << myText << endl;
    }

    return 0;
}