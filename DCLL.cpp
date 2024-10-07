#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = newNode->next = nullptr;
    return newNode;
}


void insertEnd(Node*& head, int data) {
    Node* newNode = createNode(data);

    
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    
    Node* last = head->prev;
    last->next = newNode;
    newNode->prev = last;
    newNode->next = head;
    head->prev = newNode;
}

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "empty." << endl;
        return;
    }

    Node* temp = head;
    while (true) {
        cout << temp->data << " ";
        temp = temp->next;
        if (temp == head) break;  
    }
    cout << endl;
}

void deleteNode(Node*& head, int key) {
    if (head == nullptr) return;

    Node* curr = head;
    Node* prevNode = nullptr;

    if (curr->data == key) {
        if (curr->next == head && curr->prev == head) {
            delete curr;
            head = nullptr;
            return;
        }

     
        head = head->next;

    
        Node* last = curr->prev;
        last->next = head;
        head->prev = last;
        delete curr;
        return;
    }

    while (curr->next != head) {
        if (curr->data == key) {
            prevNode = curr->prev;
            prevNode->next = curr->next;
            curr->next->prev = prevNode;
            delete curr;
            return;
        }
        curr = curr->next;
    }

    if (curr->data == key) {
        prevNode = curr->prev;
        prevNode->next = curr->next;
        curr->next->prev = prevNode;
        delete curr;
    }
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Doubly Circular Linked List: ";
    displayList(head);

    cout << "Deleting 20" << endl;
    deleteNode(head, 20);

    cout << "after deletion: ";
    displayList(head);

    return 0;
}
