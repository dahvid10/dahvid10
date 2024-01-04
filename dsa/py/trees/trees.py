# BST

# create tree
# pseudocode
# create node class
# set variables: data as default none and left, right default none
# create tree class
# initialize root as None
# code
class Node:
    def __init__(self, data = None):
        self.data = data
        self.left = None
        self.right = None

class Tree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        new_node = Node(data)
        if self.root is None:
            self.root = new_node
        else:
            self.helper_insert(self.root, new_node)
    def helper_insert(self, cur, new_node):
        if new_node.data < cur.data:
            if cur.left is None:
                cur.left = new_node
            else:
                self.helper_insert(cur.left, new_node)
        else:
            if cur.right is None:
                cur.right = new_node
            else:
                self.helper_insert(cur.right, new_node)
    def delete(self, data):
        if self.root.data is None:
            return
        elif data == self.root.data:
            # if root node has no children, set root to None
            if self.root.left == None and self.root.right == None:
                del self.root
            # if root node only has left child
            elif self.root.left and self.root.right == None:
                self.root = self.root.left
            # if root node only has right child
            elif self.root.right and self.root.left == None:
                self.root = self.root.right
            # if root node has left and right child
            else:
                old_left = self.root.left
                old_right = self.root.right
                left_child_right = self.root.left.right
                self.root.data = old_left.data
                self.root.left = old_left.left
                self.root.right = old_left.right
                cur = self.root
                while cur.right:
                    cur = cur.right
                cur.right = old_right
        else:
            self.helper_delete(self.root, data)
    def helper_delete(self, cur, data):
        if cur == None:
            return
        elif(data < cur.data):
            self.helper_delete(cur.left, data)
        elif(data > cur.data):
            self.helper_delete(cur.right, data)
        else:
            if cur.left == None and cur.right == None:
                del cur
            elif cur.left == None and cur.right:
                cur = cur.right
            elif cur.left and cur.right == None:
                cur = cur.left
            else:
                old_left = cur.left
                old_right = cur.right
                left_child_right = cur.left.right
                cur.data = old_left.data
                cur.left = old_left.left
                cur.right = old_left.right
                while cur.right:
                    cur = cur.right
                cur.right = old_right
        return
    def search(self, data):
        cur = self.root
        found = False
        while not found:
            if cur == None:
                return False
            if data == cur.data:
                return True
            if data < cur.data:
                cur = cur.left
            elif data > cur.data:
                cur = cur.right
        return
    def level_order_traversal(self):
        queue, traversal = [], []
        queue.append(self.root)
        while queue:
            cur = queue.pop(0)
            traversal.append(cur.data)
            if cur.left:
                queue.append(cur.left)
            if cur.right:
                queue.append(cur.right)
        return traversal
    def pre_order_traversal(self):
        traversal = []        
        def helper_pre_order(root):
            if root is None:
                return
            traversal.append(root.data)
            helper_pre_order(root.left)
            helper_pre_order(root.right)
            return
        helper_pre_order(self.root)
        return traversal
    def in_order_traversal(self):
        traversal = []        
        def helper_in_order(root):
            if root is None:
                return
            helper_in_order(root.left)
            traversal.append(root.data)
            helper_in_order(root.right)
            return
        helper_in_order(self.root)
        return traversal
    def post_order_traversal(self):
        traversal = []        
        def helper_post_order(root):
            if root is None:
                return
            helper_post_order(root.left)
            helper_post_order(root.right)
            traversal.append(root.data)
            return
        helper_post_order(self.root)
        return traversal


# test
tree = Tree()
node = Node()

# insert 
def pseudocode_insert():
    # pseudocode
    # create new node with input 
    # if root node of tree is null
        # set root node as input node
    # else
        # insert new node using helper fn with inputs root node as current node
    # helper fn
        # if new node is less than current node
            # if left node is none
                # set new node as left node
            # else
                # insert new node using helper fn with left node as current node
        # else:   
            # if right node is none
                # set new node as right node
            # else
                # insert new node using helper fn with right node as current node
    return

# test
tree_data = [50, 40, 80, 30, 47, 60, 90]
for data in tree_data:
    tree.insert(data)
pass

# delete
def pseudocode_delete():
    # pseudocode
    # check if root node has data
    # if root node is none
        # return
    # else if data is root node's data
        # if root node has no children
            # delete root node
        # if root node only has left child
            # set left child as root node
        # if root node only has right child
            # set right child as root node
        # if root node has left and right child
            # save left child as old_left
            # save right child as old_right
            # save left child's right child
            # set old_left as new root node
            # set current node as new root node
            # while current node has right child
                # set current node as right child
            # set current node's right child as old_right
    # else
        # search and delete node using helper fn with root node as cur node and data to delete
    # helper fn
        # if node is none
            # return
        # else if data is less than cur node's data
            # recursively call helper fn with left node as cur node and data to delete
        # else if data is greater than cur node's data
            # recursively call helper fn with right node as cur node and data to delete
        # else
            # if cur node has no children
                # delete current node
            # else if current node only has right child
                # set current node as right child
            # else if current node only has left child
                # set current node as left child
            # else
                # rotate right:
                # save left child as old_left
                # save right child as old_right
                # save left child's right child as left_right
                # set current node's data as old left's data
                # set current node's left child as old left's left child
                # set current node's right child as old left's right child
                # while current node has right child
                    # set current node as right child
                # set current node's right child as old_right
    return

# test
print(tree.level_order_traversal())

# tree.delete(80)
print(tree.level_order_traversal())

# search
def pseudocode_search():
    # pseudocode
    # set cur as root node
    # set found variable = False
    # while data not found
        # if cur is None
            # return None
        # if data is cur's data
            # return True
        # if data is less than cur's data
            # set cur as cur.left
        # else if data is greater than cur's data
            # set cur as cur.right
    return

# test
print(tree.search(20))

# pre order
print(tree.pre_order_traversal())

# in order
print(tree.in_order_traversal())

# post order
print(tree.post_order_traversal())