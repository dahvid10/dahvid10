#include <iostream>
#include <queue>

using namespace std;

class BST {

    struct node {
        int data;
        node* left;
        node* right;
    };

    node* root;

    node* insert(node* n, int data)
    {
        if (n == NULL)
        {
            n = new node;
            n->data = data;
            n->left = n->right = NULL;
        }
        else if (data < n->data)
        {
            n->left = insert(n->left, data);
        }
        else if (data > n->data)
        {
            n->right = insert(n->right, data);
        }
        return n;
    }

    // dfs: in-order, pre-order, post-order
    void inOrder(node* r) {
        if (r == NULL) {
            return;
        }
        inOrder(r->left);
        cout << r->data << " " << endl;
        inOrder(r->right);
    }

    void preOrder(node *r)
    {
        if (r == NULL)
        {
            return;
        }
        cout << r->data << " " << endl;
        preOrder(r->left);
        preOrder(r->right);
    }

    void postOrder(node *r)
    {
        if (r == NULL)
        {
            return;
        }
        
        postOrder(r->left);
        postOrder(r->right);
        cout << r->data << " " << endl;
    }

    // bfs: level-order
    void levelOrder(node *r){
        // base case
        if (r == NULL) {
            return;
        }
        // create queue for nodes
        queue<node*> q;
        // enqueue root node
        q.push(r);
        // while queue is not empty
        while (q.empty() == false) {
            // print front node, then remove it from queue
            node* n = q.front();
            cout << n->data << " ";
            q.pop();
            // enqueue left child
            if(n->left != NULL) {
                q.push(n->left);
            }
                
            // enqueue right child
            if(n->right != NULL) {
                q.push(n->right);
            }            
        }
        cout << endl;
    }

    node * findMin(node *r) {
        if(r == NULL) {
            cout << "Error: Tree is empty\n";
            return NULL;
        } else if (r->left == NULL) {
            return r;
        }
        return findMin(r->left);
    }

    node * findMax(node *r) {
        if(r == NULL) {
            cout << "Error: Tree is empty\n";
            return NULL;
        } else if (r->right == NULL) {
            return r;
        }
        return findMax(r->right);
    }

    bool search(node *r, int target)
    {
        if (r == NULL)
        {
            return false;
        }
        else if (r->data == target)
        {
            return true;
        }
        else if (r->data > target)
        {
            search(r->left, target);
        }
        else if (r->data < target)
        {
            search(r->right, target);
        }
    }

    int findHeight(node *r) {
        if (r == NULL)
        {
            return -1;
        }
        return max(findHeight(r->left), findHeight(r->right)) + 1;
    }

    int findLevel(node *r, int target) {
        // check if target in tree
        // make counter for levels (=0)
        // make variable for found state (=false)
        // set current node = root
        // while target not found
            // if target < cur
                // counter++
                // cur = cur->left
            // else if target > cur
                // counter++
                // cur = cur->right
            // else
                // counter++
                // found = true
        // return levels

        if(search(r, target) == false) {
            return -1;
        }
        
        int level = 0;
        bool found = false;
        node *cur = r;
        
        while (found == false) {
            if (target < cur->data) {
                cur = cur->left;
            } else if (target > cur->data) {
                cur = cur->right;
            } else {
                found = true;
                return level;
            }
            level++;
        }
    }

    vector<node *> treeSize(node* r, vector<node *> &v) {
        if (r == NULL)
        {
            return v;
        }
        v.push_back(r);
        treeSize(r->left, v);
        treeSize(r->right, v);
        return v;
    }

    node * deleteNode(node* r, int data) {
        // if root is null, return root
        if (r == NULL) {
            return r;
        }
        // traverse to find node
        if (data < r->data) {
            r->left = deleteNode(r->left, data);
        } else if (data > r->data) {
            r->right = deleteNode(r->right, data);
        } else {
            // case 1: no child
            if (r->left == NULL && r->right == NULL) {
                delete r;
                r = NULL;
            }
            // case 2: 1 child
            else if (r->left == NULL) {
                node *temp = r;
                r = r->right;
                delete temp;
            }
            else if (r->right == NULL) {
                node *temp = r;
                r = r->left;
                delete temp;
            }
            // case 3: 2 children
           else {
            node *temp = findMin(r->right);
            r->data = temp->data;
            r->right = deleteNode(r->right, temp->data);
           }
        }
        return r;
    }

    bool verifyBST(node * r, int minVal, int maxVal) {
        if (r == NULL) {
            return true;
        }

        if (
            r->data >= minVal
            && r->data <= maxVal
            && verifyBST(r->left, minVal, r->data)
            && verifyBST(r->right, r->data, maxVal)
        ) {
            return true;
        } else {
            return false;
        }
    }
 
    public:
        BST() {
            root = NULL;
        }

        void insert(int d) {
            root = insert(root, d);
        }

        void displayInOrder() {
            cout << "\ndisplay: in order" << endl;
            inOrder(root);
        }

        void displayPreOrder()
        {
            cout << "\ndisplay: pre order" << endl;
            preOrder(root);
        }

        void displayPostOrder()
        {
            cout << "\ndisplay: post order" << endl;
            postOrder(root);
        }

        void displayLevelOrder() {
            cout << "\ndisplay: level order" << endl;
            levelOrder(root);
        }

        void displayMin() {
            cout << "\ndisplay: min\n";
            node *minNode = findMin(root);
            if(minNode != NULL) {
                cout << findMin(root)->data << endl;
            }
        }

        void displayMax() {
            cout << "\ndisplay: max\n";
            node *maxNode = findMax(root);
            if (maxNode != NULL) {
                cout << maxNode->data << endl;
            }
        }

        void search(int target) {
            cout << "\nsearch: " << target << endl;
            if (search(root, target) == 0) {
                printf("%i not in tree\n", target);
            } else if (search(root, target) == 1) {
                printf("%i found!\n", target);
            }
        }

        void displayHeight() {
            cout << "\nheight: " << findHeight(root) << endl;
        }

        void displayLevel(int target) {
            printf("\nlevel for %i: ", target);
            int level = findLevel(root, target);
            if (level == -1) {
                printf("%i not in tree", target);
            } else {
                printf("%i\n", level);
            }
        }

        void displaySize() {
            vector<node *> v;
            vector<node *> result = treeSize(root, v);
            cout << "\nsize: " << result.size() << endl;
        }

        void remove(int data) {
            // delete node if it is in the tree
            if(search(root, data) == false) {
                printf("Node, %i, not in tree!", data);
            }
            else if (search(root, data) == true) {
                deleteNode(root, data);
            }
        }

        void isBST() {
            bool bst = verifyBST(root, findMin(root)->data, findMax(root)->data);
            if(bst == true) {
                cout << "The tree is a BST." << endl;
            } else {
                cout << "The tree is not a BST." << endl;
            }
        }
};

int main() {
    BST tree;

    // insert
    // traverse: inorder, preorder, postorder, level
    // find min and max
    // search
    // find height
    // find level of node
    // find size
    // remove
    // verify BST

    // insert
    tree.insert(10);
    tree.insert(12);
    tree.insert(5);
    tree.insert(7);
    tree.insert(3);

    // traverse
    tree.displayInOrder();
    tree.displayPreOrder();
    tree.displayPostOrder();
    tree.displayLevelOrder();

    // search
    tree.search(12);

    // find min
    tree.displayMin();

    // find max
    tree.displayMax();

    // find height
    tree.displayHeight();

    // find level
    tree.displayLevel(12);

    // find size
    tree.displaySize();

    // remove
    tree.search(7);
    tree.remove(7);
    tree.displayInOrder();
    tree.search(7);

    // verify BST
    tree.isBST();


    return 0;
}