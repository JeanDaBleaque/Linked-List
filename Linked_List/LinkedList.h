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
        int index;
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
    };
    void add(Type objValue) {
        if (isEmpty()) {
            Node *nextNode = new Node(objValue);
            head = nextNode;
            tail = head;
            nextNode->index = objectSize;
            objectSize++;
        } else {
            Node *nextNode = new Node(objValue);
            tail->next = nextNode;
            nextNode->previous = tail;
            tail = tail->next;
            nextNode->index = objectSize;
            objectSize++;
        }
    };
    void pushToIndex(Type objValue, int index) {
        //WIP
    };
    void remove(Node *ptr) {
        if (!isEmpty()) {
            Node *pointer = head;
            while (pointer != NULL) {
                if (pointer == ptr) {
                    decreaseTillEnd(pointer->next);
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
    void remove(int index) {
        try {
            if (index>=objectSize) {
                throw 0;
            } else if (index<0) {
                throw 1;
            }
            int fromStart = index - 0;
            int fromEnd = objectSize - index;
            if (fromStart<=fromEnd) {
                Node* selectedNode = head;
                while (selectedNode->index != index) {
                    selectedNode = selectedNode->next;
                }
                removeFromIndex(selectedNode);
            } else {
                Node* selectedNode = tail;
                while (selectedNode->index != index) {
                    selectedNode = selectedNode->previous;
                }
                removeFromIndex(selectedNode);
            }
        } catch (int error) {
            switch (error) {
            case 0:
                std::cout << "The object which selected by index is nullptr!" << std::endl;
                break;
            case 1:
                std::cout << "Selected index can't be negative!" << std::endl;
                break;
            }
        }
    };
    void removeFromIndex(Node *selectedNode) {
        decreaseTillEnd(selectedNode->next);
        Node *prev = selectedNode->previous;
        Node *next = selectedNode->next;
        if (prev != NULL) {
            prev->next = next;
        }
        if (next != NULL) {
            next->previous = prev;
        }
        if (selectedNode == head) {
            head = next;
        } else if (selectedNode == tail) {
            tail = prev;
        }
        delete(selectedNode);
    };
    void decreaseTillEnd(Node* startNode) {
        if (startNode != NULL) {
            startNode->index--;
            decreaseTillEnd(startNode->next);
        }
    };
    Node* get(int index) {
        try {
            if (index>=objectSize) {
                throw 0;
            } else if (index<0) {
                throw 1;
            }
            int fromStart = index - 0;
            int fromEnd = objectSize - index;
            if (fromStart<=fromEnd) {
                Node* selectedNode = head;
                while (selectedNode->index != index) {
                    selectedNode = selectedNode->next;
                }
                return selectedNode;
            } else {
                Node* selectedNode = tail;
                while (selectedNode->index != index) {
                    selectedNode = selectedNode->previous;
                }
                return selectedNode;
            }
        } catch (int error) {
            switch (error) {
            case 0:
                std::cout << "The object which selected by index is nullptr!" << std::endl;
                break;
            case 1:
                std::cout << "Selected index can't be negative!" << std::endl;
                break;
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
                std::cout << "Value: " << pointer->value << " Index: " << pointer->index << std::endl;
                pointer = pointer->next;
            }
        }
    };
};

#endif // LIST_H
