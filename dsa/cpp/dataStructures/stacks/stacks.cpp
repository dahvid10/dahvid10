#include <iostream>
#include <stack>

using namespace std;

int main() {
    cout << "Stacks" << endl;

    stack<int> s;

    for (int i=0; i<3; i++) {
        s.push(i+1);
    }

    int n = s.size();

    for (int i=0; i<n; i++) {
        cout << s.top() << endl;
        s.pop();
    }

    cout << "Lift off!" << endl;

    if(s.empty()) {
        cout << "The stack is empty." << endl;
    }
    

    return 0;
}