#ifndef LIST_H
#define LIST_H
#include <iostream>
template <class Type>

class List {
public:
    class Node {
        public:
        Node(Type value) {
            this->value = value;
        }
        Type value;
        Node *next = nullptr;
        Node *previous = nullptr;
    };
    int objectSize = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
public:
    int size() {
        return objectSize;
    };
    bool isEmpty() {
        if (head == NULL) {
            return true;
        } else {
            return false;
        }
    }
    void add(Type objValue) {
        if (isEmpty()) {
            Node *nextNode = new Node(objValue);
            head = nextNode;
            tail = head;
            objectSize++;
        } else {
            Node *nextNode = new Node(objValue);
            tail->next = nextNode;
            nextNode->previous = tail;
            tail = tail->next;
            objectSize++;
        }
    };
    void remove(Node *ptr) {
        if (!isEmpty()) {
            Node *pointer = head;
            while (pointer != NULL) {
                if (pointer == ptr) {
                    Node *prev = ptr->previous;
                    Node *next = ptr->next;
                    if (prev != NULL) {
                        prev->next = next;
                    }
                    if (next != NULL) {
                        next->previous = prev;
                    }
                    if (ptr == head) {
                        head = next;
                    } else if (ptr == tail) {
                        tail = prev;
                    }
                    pointer = nullptr;
                    delete(ptr);
                    break;
                }
                pointer = pointer->next;
            }
        }
    };
    Node* getHead() {
        return head;
    };
    Node* getTail() {
        return tail;
    };
    void printAll() {
        if (!isEmpty()) {
            Node *pointer = head;
            while (pointer != NULL) {
                std::cout << pointer->value << std::endl;
                pointer = pointer->next;
            }
        }
    };
};

#endif // LIST_H
