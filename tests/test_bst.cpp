#include <iostream>
#include "../include/dsa/BST.hpp"

using namespace std;

int main() {

    BST bst;

    // -------- Test Insert --------
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // -------- Test Search --------
    cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 90: " << (bst.search(90) ? "Found" : "Not Found") << endl;

    // -------- Test Traversals --------
    auto inorder = bst.getInorder();
    auto preorder = bst.getPreorder();
    auto postorder = bst.getPostorder();

    cout << "\nInorder: ";
    for (int x : inorder) cout << x << " ";
    cout << "\n";

    cout << "Preorder: ";
    for (int x : preorder) cout << x << " ";
    cout << "\n";

    cout << "Postorder: ";
    for (int x : postorder) cout << x << " ";
    cout << "\n";

    // -------- Test Delete --------
    bst.remove(20);  // leaf delete
    bst.remove(70);  // node with children

    cout << "\nInorder After Deletions: ";
    inorder = bst.getInorder();
    for (int x : inorder) cout << x << " ";
    cout << "\n";

    return 0;
}
