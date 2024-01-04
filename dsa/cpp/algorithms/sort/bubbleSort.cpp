#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> v) {
    for (int i = 0; i < v.size()-1; i++) {
        for (int j = 0; j < v.size()-i-1; j++) {
            if (v[j] > v[j+1]) {
                // int temp = v[j];
                // v[j] = v[j+1];
                // v[j+1] = temp;
                swap(v[j], v[j+1]);
            }
        }
    }
    return v;
}

int* bubbleSort(int arr[]) {
    int size = sizeof(&arr)/sizeof(int);
    for (int i=0; i<size-1; i++) {
        for (int j=0; j<size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j+1];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr;
}

int main() {
    vector<int> sample_v = {6,34,24,32,23, 4};
    vector<int> sorted_v = bubbleSort(sample_v);
    int arr[6] = {6, 34, 24, 32, 23, 4};
    // int sorted_arr[6] = bubbleSort(arr);

    for (int num : sorted_v) {
        cout << num << " ";
    }
    for (int i = 0; i < sorted_v.size(); i++)
    {
        cout << endl << sorted_v[i];
    }

    return 0;
}

