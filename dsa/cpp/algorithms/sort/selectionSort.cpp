#include <iostream>
#include <vector>

using namespace std;

vector<int> selectionSort(vector<int> v) {
    for (int i=0; i<v.size(); i++) {
        int minInd = i;
        for (int j=i+1; j<v.size(); j++) {
            if(v[j] < v[i]) {
                minInd = j;
            }
        }
        swap(v[minInd], v[i]);
        // int temp = v[i];
        // v[i] = v[minInd];
        // v[minInd] = temp;
    }
    
    return v;
}

int main()
{
    vector<int> sample_v = {6, 34, 24, 32, 23, 4};
    vector<int> sorted_v = selectionSort(sample_v);
    int arr[6] = {6, 34, 24, 32, 23, 4};
    // int sorted_arr[6] = bubbleSort(arr);

    for (int num : sorted_v)
    {
        cout << num << " ";
    }
    return 0;
}

