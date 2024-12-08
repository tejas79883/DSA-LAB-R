 #include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

class BST {
    Node *root;

public:
    BST();
    Node *getroot();
    void insert();
    void del(int);
    Node *delete_Node(Node *, int);
    void mirror_tree(Node *);
    void search(int);
    void display(Node *);
    void display_level();
    int height_tree(Node *);
};

BST::BST() : root(NULL) {}

Node *BST::getroot() {
    return root;
}

void BST::insert() {
	char ch = 'y';

    while(ch == 'y' || ch == 'Y')
    {
    Node *newNode = new Node();
    cout << "\nEnter data for new Node: ";
    cin >> newNode->data;
    newNode->left = newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
        break;
    }

    Node *temp = root;
    while (temp!=NULL) {
        if (newNode->data < temp->data) {
            if (temp->left == NULL) {
                temp->left = newNode;
                 break;
            }
            temp = temp->left;
        } else if (newNode->data > temp->data) {
            if (temp->right == NULL) {
                temp->right = newNode;
                 break;
            }
            temp = temp->right;
        }
    }
    cout<<"\nEnter y or Y to add more Nodes: ";
        cin>>ch;
    }

}

void BST::del(int x) {
    root = delete_Node(root, x);
}

Node *BST::delete_Node(Node *t, int x) {
    if (t == NULL)
        return t;

    if (x < t->data)
        t->left = delete_Node(t->left, x);
    else if (x > t->data)
        t->right = delete_Node(t->right, x);
    else {   //If the node with value x is found, this block handles three cases
    
    //1)If the node has no left child, it replaces the current node with its right child.

        if (t->left == NULL) {
            Node *temp = t->right;
            delete t;
            return temp;
        //2) If the node has no right child, it replaces the current node with its left child.

        } else if (t->right == NULL) {
            Node *temp = t->left;
            delete t;
            return temp;
        }
       // 3)If the node has both left and right children, it finds the minimum value node in 
	   // the right subtree (the leftmost node in the right subtree) and replaces the current 
	   // node's value with that minimum value. Then, it recursively deletes the node with the minimum 
	   // value in the right subtree.

        Node *temp = t->right;
        while (temp->left)
            temp = temp->left;

        t->data = temp->data;
        t->right = delete_Node(t->right, temp->data);
    }
    return t;
}

void BST::mirror_tree(Node *t) {
    if (t) {
        swap(t->left, t->right);
        mirror_tree(t->left);
        mirror_tree(t->right);
    }
}

void BST::search(int no) {
    Node *temp = root;
    while (temp) {
        if (no == temp->data) {
            cout << "\nData found!";
            return;
        } else if (no < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    cout << "\nData doesn't exist.";
}

void BST::display(Node *root) {
    if (root) {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

void BST::display_level() {
	//It creates a queue of pointers to nodes (Node *) to store the nodes during the traversal.
    queue<Node *> q;
    if (root == NULL)
        return;
/*Traversal using Queue:

Enqueue the root node onto the queue.
While the queue is not empty:
Dequeue a node from the front of the queue.
Print the data of the current node.
Enqueue the left and right children of the current node if they exist.
        10
       /  \
      5   15
     / \    \
    3   7   20
The display_level function would print: 10 5 15 3 7 20 
as it traverses the tree level by level, from the root to the leaves.
*/
    q.push(root);

    while (!q.empty()) {
        Node *curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int BST::height_tree(Node *t) {
    if (t == NULL)
        return 0;

    int hlt = height_tree(t->left) + 1;
    int hrt = height_tree(t->right) + 1;

    return max(hlt, hrt);
}

int main() {
    BST tree;
    int x, choice;

    while (true) {
        cout << "\n\nBinary Search Tree Operations ";
        cout << "\n1. Insert.";
        cout << "\n2. Delete.";
        cout << "\n3. Search.";
        cout << "\n4. Mirror Image.";
        cout << "\n5. Display.(Inorder recursive traversal of tree)";
        cout << "\n6. Display Level-wise.(BST)";
        cout << "\n7. Height of the tree.";
        cout << "\n8. Exit.";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            tree.insert();
            break;

        case 2:
            cout << "\nEnter data to delete: ";
            cin >> x;
            tree.del(x);
            break;

        case 3:
            cout << "\nEnter number to search: ";
            cin >> x;
            tree.search(x);
            break;

        case 4:
            cout << "\nMirror Image of tree: ";
            tree.mirror_tree(tree.getroot());
            tree.display(tree.getroot());
            tree.mirror_tree(tree.getroot());
            break;

        case 5:
            cout << "\nInorder traversal of tree: ";
            tree.display(tree.getroot());
            break;

        case 6:
            cout << "\nLevel-Order traversal of tree: ";
            tree.display_level();
            break;

        case 7:
            cout << "\nHeight of the tree: " << tree.height_tree(tree.getroot());
            break;

        case 8:
            return 0;
        }
    }

    return 0;
}

