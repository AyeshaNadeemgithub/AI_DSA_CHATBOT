#include "dsa/LinkedList.hpp"

//
// ========================= SINGLY LINKED LIST =========================
//

SinglyLinkedList::SinglyLinkedList() {
    head = nullptr;
}

void SinglyLinkedList::insertAtHead(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void SinglyLinkedList::insertAtTail(int value) {
    Node* newNode = new Node(value);

    if(head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

SinglyLinkedList::Node* SinglyLinkedList::deleteHelper(Node* head, int value) {
    if(head == nullptr) return nullptr;

    if(head->data == value) {
        Node* next = head->next;
        delete head;
        return next;
    }

    head->next = deleteHelper(head->next, value);
    return head;
}

void SinglyLinkedList::deleteValue(int value) {
    head = deleteHelper(head, value);
}

bool SinglyLinkedList::searchHelper(Node* head, int value) {
    if(head == nullptr) return false;
    if(head->data == value) return true;
    return searchHelper(head->next, value);
}

bool SinglyLinkedList::search(int value) {
    return searchHelper(head, value);
}

vector<int> SinglyLinkedList::getAll() {
    vector<int> arr;
    Node* temp = head;
    while(temp != nullptr) {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return arr;
}

void SinglyLinkedList::display() {
    Node* temp = head;
    cout << "[ ";
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "]" << endl;
}


//
// ========================= DOUBLY LINKED LIST =========================
//

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

void DoublyLinkedList::insertAtHead(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;

    if(head != nullptr)
        head->prev = newNode;

    head = newNode;

    if(tail == nullptr)
        tail = newNode;
}

void DoublyLinkedList::insertAtTail(int value) {
    Node* newNode = new Node(value);

    if(tail == nullptr) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void DoublyLinkedList::deleteValue(int value) {

    Node* temp = head;

    while(temp != nullptr && temp->data != value)
        temp = temp->next;

    if(temp == nullptr) return;

    if(temp->prev != nullptr)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != nullptr)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    delete temp;
}

bool DoublyLinkedList::search(int value) {
    Node* temp = head;
    while(temp != nullptr) {
        if(temp->data == value)
            return true;
        temp = temp->next;
    }
    return false;
}

vector<int> DoublyLinkedList::getForward() {
    vector<int> arr;
    Node* temp = head;
    while(temp != nullptr) {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return arr;
}

vector<int> DoublyLinkedList::getBackward() {
    vector<int> arr;
    Node* temp = tail;
    while(temp != nullptr) {
        arr.push_back(temp->data);
        temp = temp->prev;
    }
    return arr;
}

void DoublyLinkedList::displayForward() {
    Node* temp = head;
    cout << "[ ";
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "]" << endl;
}

void DoublyLinkedList::displayBackward() {
    Node* temp = tail;
    cout << "[ ";
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << "]" << endl;
}


//
// ========================= CIRCULAR LINKED LIST =========================
//

CircularLinkedList::CircularLinkedList() {
    head = nullptr;
}

void CircularLinkedList::insert(int value) {

    Node* newNode = new Node(value);

    if(head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void CircularLinkedList::deleteValue(int value) {

    if(head == nullptr) return;

    Node* temp = head;
    Node* prev = nullptr;

    while(temp->data != value) {
        if(temp->next == head) return; 
        prev = temp;
        temp = temp->next;
    }

    if(temp == head && temp->next == head) {
        head = nullptr;
        delete temp;
        return;
    }

    if(temp == head) {
        Node* last = head;
        while(last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        delete temp;
        return;
    }

    prev->next = temp->next;
    delete temp;
}

bool CircularLinkedList::search(int value) {
    if(head == nullptr) return false;

    Node* temp = head;
    do {
        if(temp->data == value) return true;
        temp = temp->next;
    } while(temp != head);

    return false;
}

vector<int> CircularLinkedList::getAll() {
    vector<int> arr;

    if(head == nullptr) return arr;

    Node* temp = head;
    do {
        arr.push_back(temp->data);
        temp = temp->next;
    } while(temp != head);

    return arr;
}

void CircularLinkedList::display() {
    if(head == nullptr) {
        cout << "[]\n";
        return;
    }

    Node* temp = head;
    cout << "[ ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);
    cout << "]" << endl;
}