#include <iostream>

using namespace std;

int main() {
    cout << "Arrays" << endl;

    int arr[5];
    for (int i=0; i < sizeof(arr)/sizeof(int); i++) {
        arr[i] = i+1;
        cout << arr[i] << endl;
    }

    return 0;
}