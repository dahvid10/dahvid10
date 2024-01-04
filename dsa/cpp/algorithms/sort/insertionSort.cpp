#include <iostream>
#include <vector>

using namespace std;

// loop through all elements of array
    // get element at current index
    // loop through other elements in array
        // if element found less than element at current index
            // swap elements

vector<int> insertionSort(vector<int> v) {
    for (int i = 0; i<v.size(); i++) {
        for (int j=i+1; j<v.size(); j++) {
            if (v[j] < v[i]) {
                swap(v[j], v[i]);
                // int temp = v[j];
                // v[j] = v[i];
                // v[i] = temp;
            }
        }
    }
    return v;
}

int main()
{
    vector<int> sample_v = {6, 34, 24, 32, 23, 4};
    vector<int> sorted_v = insertionSort(sample_v);

    for (int num : sorted_v)
    {
        cout << num << " ";
    }

    return 0;
}

