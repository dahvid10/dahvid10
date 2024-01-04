#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l;
    for (int i=0; i<5; i++) {
        l.push_back(i);
    }

    for (auto i : l) {
        cout << i << endl;
    }
    
    list<int>::iterator i = l.begin();
    advance(i,2);

    cout << endl << *i;

    return 0;
}