# include <iostream>

using namespace std;

struct Node {
    int data; // variable to store node's data
    Node *next; // variable to store pointer for next node in linked list
};

typedef Node* nodePtr;

void insert(nodePtr &tail, int data)
{
    nodePtr tmpPtr; // create temporary node pointer
    tmpPtr = new Node; // set temporary node pointer to new node
    tmpPtr -> data = data; // set data of new node
    tmpPtr -> next = NULL; // set next node of new node as null
    tail -> next = tmpPtr; // set next node of tail as new node
    tail = tmpPtr; // set tail as new node
}

int main() {
    cout << "Linked List - insert left to right" << endl;

    nodePtr head; //create node pointer for head node
    head = new Node; // set node pointer to new node
    head->data = 10; // set data for head node
    head->next = NULL; // set next node of head as null
    nodePtr tail = head; // create node pointer for tail node to be same as head

    insert(tail, 11); // insert new node to linked list with data = 11
    insert(tail, 12); // insert new node to linked list with data = 12

    nodePtr tmp; // create temporary node pointer
    tmp = head; // set temporary node pointer to head of linked list

    // while temporary node pointer is not NULL,
    // print data for nodes in linked list
    while (tmp != NULL) {
        cout << tmp -> data << endl;
        tmp = tmp -> next;
    }

    return 0;
}
