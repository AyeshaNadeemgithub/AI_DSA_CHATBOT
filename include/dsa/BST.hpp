#pragma once
#include <vector>
using namespace std;

class BST {
private:
    // Node structure for BST
    struct Node {
        int value;
        Node* left;
        Node* right;
        Node(int v) : value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper functions
    Node* insertNode(Node* node, int value);
    bool searchNode(Node* node, int value);
    Node* deleteNode(Node* node, int value);
    int findMin(Node* node);

    void inorder(Node* node, vector<int>& result);
    void preorder(Node* node, vector<int>& result);
    void postorder(Node* node, vector<int>& result);

public:
    BST();

    // Main operations
    void insert(int value);
    bool search(int value);
    void remove(int value);

    vector<int> getInorder();
    vector<int> getPreorder();
    vector<int> getPostorder();
};
