#include <iostream>
#include <queue>

using namespace std;

int main() {
    cout << "Queues" << endl;

    queue<int> q;

    for (int i = 0; i < 3; i++) {
        q.push(i+1);
    }
    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;
    cout << "length of queue: " << q.size() << endl << endl;

    
    int length = q.size();

    for (int i = 0; i < length; i++) {
        cout << "Ticket number " << q.front() << " step up please!" << endl;
        q.pop();
        if (q.front() > 0) {
            cout << "Next up is ticket number " << q.front() << endl;
            cout << "Last in line is ticket number " << q.back() << endl << endl;
        } else {
            cout << "No more tickets for the day!" << endl;
        }
        
        
    }

    return 0;
}