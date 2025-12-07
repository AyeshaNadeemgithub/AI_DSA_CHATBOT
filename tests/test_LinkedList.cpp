#include <iostream>
#include "dsa/LinkedList.hpp"

using namespace std;

int main() {

    cout << "===== TESTING SINGLY LINKED LIST =====" << endl;
    SinglyLinkedList sll;

    sll.insertAtHead(10);
    sll.insertAtHead(20);
    sll.insertAtTail(5);
    sll.insertAtTail(1);

    vector<int> sll_data = sll.getAll();
    cout << "SLL elements: ";
    for (int x : sll_data) cout << x << " ";
    cout << endl;

    cout << "Search 5: " << (sll.search(5) ? "Found" : "Not Found") << endl;

    sll.deleteValue(20);
    cout << "After deleting 20 → ";
    sll.display();


    cout << "\n===== TESTING DOUBLY LINKED LIST =====" << endl;
    DoublyLinkedList dll;

    dll.insertAtHead(30);
    dll.insertAtHead(40);
    dll.insertAtTail(20);
    dll.insertAtTail(10);

    cout << "DLL forward: ";
    for (int x : dll.getForward()) cout << x << " ";
    cout << endl;

    cout << "DLL backward: ";
    for (int x : dll.getBackward()) cout << x << " ";
    cout << endl;

    dll.deleteValue(40);
    cout << "After deleting 40 → ";
    dll.displayForward();


    cout << "\n===== TESTING CIRCULAR LINKED LIST =====" << endl;
    CircularLinkedList cll;

    cll.insert(1);
    cll.insert(2);
    cll.insert(3);

    cout << "CLL elements: ";
    for (int x : cll.getAll()) cout << x << " ";
    cout << endl;

    cout << "Search 2: " << (cll.search(2) ? "Found" : "Not Found") << endl;

    cll.deleteValue(2);
    cout << "After deleting 2 → ";
    cll.display();

    return 0;
}