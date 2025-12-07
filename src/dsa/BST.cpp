#include "dsa/BST.hpp"

// ----------------------------------
// Constructor
// ----------------------------------
BST::BST() : root(nullptr) {}


// ----------------------------------
// INSERT
// ----------------------------------
BST::Node* BST::insertNode(Node* node, int value) {
    if (node == nullptr)
        return new Node(value);

    if (value < node->value)
        node->left = insertNode(node->left, value);
    else
        node->right = insertNode(node->right, value);

    return node;
}

void BST::insert(int value) {
    root = insertNode(root, value);
}


// ----------------------------------
// SEARCH
// ----------------------------------
bool BST::searchNode(Node* node, int value) {
    if (!node) return false;

    if (node->value == value) return true;

    if (value < node->value)
        return searchNode(node->left, value);

    return searchNode(node->right, value);
}

bool BST::search(int value) {
    return searchNode(root, value);
}


// ----------------------------------
// DELETE
// ----------------------------------
int BST::findMin(Node* node) {
    while (node->left != nullptr)
        node = node->left;
    return node->value;
}

BST::Node* BST::deleteNode(Node* node, int value) {
    if (!node) return nullptr;

    if (value < node->value) {
        node->left = deleteNode(node->left, value);
    }
    else if (value > node->value) {
        node->right = deleteNode(node->right, value);
    }
    else {
        // Case 1: leaf node
        if (!node->left && !node->right) {
            delete node;
            return nullptr;
        }

        // Case 2: one child
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Case 3: two children
        int minVal = findMin(node->right);
        node->value = minVal;
        node->right = deleteNode(node->right, minVal);
    }

    return node;
}

void BST::remove(int value) {
    root = deleteNode(root, value);
}


// ----------------------------------
// TRAVERSALS
// ----------------------------------
void BST::inorder(Node* node, vector<int>& result) {
    if (!node) return;
    inorder(node->left, result);
    result.push_back(node->value);
    inorder(node->right, result);
}

vector<int> BST::getInorder() {
    vector<int> result;
    inorder(root, result);
    return result;
}

void BST::preorder(Node* node, vector<int>& result) {
    if (!node) return;
    result.push_back(node->value);
    preorder(node->left, result);
    preorder(node->right, result);
}

vector<int> BST::getPreorder() {
    vector<int> result;
    preorder(root, result);
    return result;
}

void BST::postorder(Node* node, vector<int>& result) {
    if (!node) return;
    postorder(node->left, result);
    postorder(node->right, result);
    result.push_back(node->value);
}

vector<int> BST::getPostorder() {
    vector<int> result;
    postorder(root, result);
    return result;
}
