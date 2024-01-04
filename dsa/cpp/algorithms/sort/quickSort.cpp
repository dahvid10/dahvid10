#include <iostream>
#include <vector>

using namespace std;

vector<int> quickSort(vector<int> &v) {
    // return array if its length <= 1
    if(v.size() <= 1) {
        return v;
    }
    // extract pivot (middle element)
    int pivotInd = v.size() / 2;
    int pivot = v[pivotInd];
    v.erase(v.begin()+pivotInd);
    // partition array: left (<= pivot) and right (> pivot)
    vector<int> l, r;
    for (int num : v) {
        if (num <= pivot) {
            l.push_back(num);
        } else {
            r.push_back(num);
        }
    }
    // recursively sort left partition
    vector<int> sorted_v = quickSort(l);
    // append pivot to sorted partition
    sorted_v.push_back(pivot);
    // recursively sort right partition
    vector<int> sorted_r = quickSort(r);
    // append sorted right partition to sorted array
    sorted_v.insert(sorted_v.end(), sorted_r.begin(), sorted_r.end());
    // return sorted array
    return sorted_v;
}

int main()
{
    vector<int> sample_v = {6, 34, 24, 32, 23};
    vector<int> sorted_v = quickSort(sample_v);

    for (int num : sorted_v)
    {
        cout << num << " " << endl;
    }
    return 0;
}

