#include <iostream>
#include <queue>
using namespace std;

class node {
    public:
        int data;
        node *left;
        node *right;

    node (int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void LevelOrderTraversal (node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
    cout << endl;
}

// void ReverseLevelOrderTraversal(node* root) {

// }

void InOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    // LNR
    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

void PreOrderTraversal (node* root) {
    if (root == NULL) {
        return;
    }

    // NLR
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal (node* root) {
    if (root == NULL) {
        return;
    }

    // LRN
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
node* buildTree(node* root) {
    int data;
    cout << "Enter data for root:" << endl;
    cin >> data;
    root = new node(data);

    if (data == -1) {
        return NULL;
    }

    cout << "Moving to the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Moving to the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int main() {
    node* root = NULL;
    
    root = buildTree(root);
    LevelOrderTraversal(root);
    InOrderTraversal(root);
    cout << endl;
    PreOrderTraversal(root);
    cout << endl;
    PostOrderTraversal(root);
    cout << endl;
    // ReverseLevelOrderTraversal(root);
    
    return 0;
}
