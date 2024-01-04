#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

typedef Node *nodePtr;

void insert(nodePtr &head, int data)
{
    nodePtr tmpPtr;      // create temporary node pointer
    tmpPtr = new Node;   // set temporary node pointer to new node (store mem addr of new node to tmp ptr)
    tmpPtr->data = data; // set data of new node
    tmpPtr->next = head; // set next node as current head node
    head = tmpPtr;       // set head as tmpPtr
}

int main() {
    cout << "Linked List - insert right to left" << endl;

    nodePtr head; // create node pointer for head node
    head = new Node; // set head pointer to new node
    head -> data = 12; // set head node data as 12
    head -> next = NULL; // set next node for head node as NULL

    insert(head, 11); // insert node with data '11' to linked list
    insert(head, 10); // insert node with data '10' to linked list

    nodePtr tmp; // create temporary node pointer
    tmp = head; // set temporary node pointer to point at head node in linked list

    // while next node is not null (not reached end of linked list),
    //  print data for nodes in linked list
    while (tmp != NULL) {
        cout << tmp -> data << endl;
        tmp = tmp -> next;
    }

    return 0;
}

