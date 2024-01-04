#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<int, string> m;

    for (int i=0; i<5; i++) {
        m[i] = to_string(i*11) + "a";
    }
    
    for (int i=0; i<m.size(); i++) {
        cout << m[i] << endl;
    }

    return 0;
}