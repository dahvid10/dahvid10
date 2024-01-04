#include <iostream>
#include <vector>
#include "../sort/mergeSort.cpp"

using namespace std;

bool binarySearch(vector<int> &v, int target) {
    // while !found or v.size<1
        // get mid index
        // if mid == target
            // found = true
        // else if (mid < target)
            // set v[mid+1:]
        // else if (mid > target)
            // set v[:mid+1]
    // if (v.size == 1)
        // found = v[0] == target

    bool found = false;
    while(!found && v.size()>1) {
        int mid = v.size()/2;
        if(v[mid] == target) {
            found = true;
        } else if (v[mid] < target) {
            v = vector<int>(v.begin()+mid, v.end());
            for (auto num : v) {
                cout << num << " ";
            }
            cout << endl;
        } else if (v[mid] > target) {
            v = vector<int>(v.begin(), v.begin()+mid);
            for (auto num : v) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
    if (v.size() == 1) {
        found = v[0] == target;
    }
    return found;
}

int main()
{
    vector<int> sample_v = {6, 34, 24, 32, 23};
    vector<int> sorted_v = merge_sort(sample_v);
    for (int num : sorted_v) {
        cout << num << endl;
    }

    cout << (binarySearch(sorted_v, 32)) << endl;

    return 0;
}