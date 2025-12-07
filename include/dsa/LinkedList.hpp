#pragma once
#include <iostream>
#include <vector>
using namespace std;

// ========================= SINGLY LINKED LIST =========================

class SinglyLinkedList {

private:

    struct Node {
        int data;
        Node* next;
        Node(int val) {
            data = val;
            next = nullptr;
        }
    };

    Node* head;

    Node* deleteHelper(Node* head, int value);
    bool searchHelper(Node* head, int value);

public:
    SinglyLinkedList();

    void insertAtHead(int value);
    void insertAtTail(int value);
    void deleteValue(int value);
    bool search(int value);
    vector<int> getAll();
    void display();
};


// ========================= DOUBLY LINKED LIST =========================

class DoublyLinkedList {

private:

    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int val) {
            data = val;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList();

    void insertAtHead(int value);
    void insertAtTail(int value);
    void deleteValue(int value);
    bool search(int value);
    vector<int> getForward();
    vector<int> getBackward();
    void displayForward();
    void displayBackward();
};


// ========================= CIRCULAR LINKED LIST =========================

class CircularLinkedList {

private:

    struct Node {
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = nullptr;
        }
    };

    Node* head;

public:
    CircularLinkedList();

    void insert(int value);
    void deleteValue(int value);
    bool search(int value);
    vector<int> getAll();
    void display();
};