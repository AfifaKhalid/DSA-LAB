#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};

class SingleLinkedList {
private:
    Node* head;

public:
    SingleLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, NULL};

        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertAfterData(int value, int targetValue) {
        Node* newNode = new Node{value, NULL};
        Node* current = head;

        while (current) {
            if (current->data == targetValue) {
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }

        std::cout << "Target value not found in the list." << std::endl;
    }

    void deleteNode(int value) {
        Node* current = head;
        Node* prev = NULL;

        while (current) {
            if (current->data == value) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }

        std::cout << "Value not found in the list." << std::endl;
    }

    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* nextNode = NULL;

        while (current) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
    }

    bool seek(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        if (!head) {
            tail = newNode;
        } else {
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, NULL};

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAfterData(int value, int targetValue) {
        Node* newNode = new Node{value, NULL};
        Node* current = head;

        while (current) {
            if (current->data == targetValue) {
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next) {
                    current->next->prev = newNode;
                }
                current->next = newNode;
                return;
            }
            current = current->next;
        }

        std::cout << "Target value not found in the list." << std::endl;
    }

    void deleteNode(int value) {
        Node* current = head;

        while (current) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }

        std::cout << "Value not found in the list." << std::endl;
    }

    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void reverse() {
        Node* temp = NULL;
        Node* current = head;

        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp) {
            head = temp->prev;
        }
    }

    bool seek(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        if (!head) {
            newNode->next = newNode;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
        }
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, head};
        if (!head) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertAfterData(int value, int targetValue) {
        Node* newNode = new Node{value, NULL};
        Node* current = head;

        while (current) {
            if (current->data == targetValue) {
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
            if (current == head) {
                std::cout << "Target value not found in the list." << std::endl;
                return;
            }
        }
    }

    void deleteNode(int value) {
        if (!head) {
            std::cout << "Value not found in the list." << std::endl;
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        do {
            if (current->data == value) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    Node* temp = current;
                    while (temp->next != head) {
                        temp = temp->next;
                    }
                    temp->next = current->next;
                    head = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);

        std::cout << "Value not found in the list." << std::endl;
    }

    void display() {
        if (!head) {
            std::cout << "Circular Linked List is empty." << std::endl;
            return;
        }

        Node* current = head;

        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);

        std::cout << std::endl;
    }

    void reverse() {
        std::cout << "Reversing a circular linked list is not implemented." << std::endl;
    }

    bool seek(int value) {
        Node* current = head;

        if (!current) {
            return false;
        }

        do {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        } while (current != head);

        return false;
    }
};

int main() {
    SingleLinkedList singleLinkedList;
    DoublyLinkedList doubleLinkedList;
    CircularLinkedList circularLinkedList;

    int choice1, choice2, value, targetValue;

    while (true) {
        std::cout << "Which linked list you want:" << std::endl;
        std::cout << "1: Single" << std::endl;
        std::cout << "2: Double" << std::endl;
        std::cout << "3: Circular" << std::endl;
        std::cout << "Enter your choice (1/2/3): ";
        std::cin >> choice1;

        if (choice1 == 1) {
            std::cout << "Which operation you want to perform:" << std::endl;
            std::cout << "1: Insertion" << std::endl;
            std::cout << "2: Deletion" << std::endl;
            std::cout << "3: Display" << std::endl;
            std::cout << "4: Reverse" << std::endl;
            std::cout << "5: Seek" << std::endl;
            std::cout << "6: Exit" << std::endl;
            std::cout << "Enter your choice (1/2/3/4/5/6): ";
            std::cin >> choice2;

            switch (choice2) {
                case 1:
                    std::cout << "1: Insertion at beginning" << std::endl;
                    std::cout << "2: Insertion at end" << std::endl;
                    std::cout << "3: Insertion at specific data node" << std::endl;
                    std::cout << "Enter your choice (1/2/3): ";
                    std::cin >> choice2;

                    std::cout << "Enter the value to insert: ";
                    std::cin >> value;

                    switch (choice2) {
                        case 1:
                            singleLinkedList.insertAtBeginning(value);
                            break;
                        case 2:
                            singleLinkedList.insertAtEnd(value);
                            break;
                        case 3:
                            std::cout << "Enter the target value after which to insert: ";
                            std::cin >> targetValue;
                            singleLinkedList.insertAfterData(value, targetValue);
                            break;
                        default:
                            std::cout << "Invalid choice." << std::endl;
                            break;
                    }
                    break;
                case 2:
                    std::cout << "Enter the value to delete: ";
                    std::cin >> value;
                    singleLinkedList.deleteNode(value);
                    break;
                case 3:
                    std::cout << "Single Linked List: ";
                    singleLinkedList.display();
                    break;
                case 4:
                    singleLinkedList.reverse();
                    std::cout << "Single Linked List reversed." << std::endl;
                    break;
                case 5:
                    std::cout << "Enter the value to seek: ";
                    std::cin >> value;
                    if (singleLinkedList.seek(value)) {
                        std::cout << "Value found in the list." << std::endl;
                    } else {
                        std::cout << "Value not found in the list." << std::endl;
                    }
                    break;
                case 6:
                    exit(0);
                default:
                    std::cout << "Invalid choice." << std::endl;
                    break;
            }
        } else if (choice1 == 2) {
            std::cout << "Which operation you want to perform:" << std::endl;
            std::cout << "1: Insertion" << std::endl;
            std::cout << "2: Deletion" << std::endl;
            std::cout << "3: Display" << std::endl;
            std::cout << "4: Reverse" << std::endl;
            std::cout << "5: Seek" << std::endl;
            std::cout << "6: Exit" << std::endl;
            std::cout << "Enter your choice (1/2/3/4/5/6): ";
            std::cin >> choice2;

            switch (choice2) {
                case 1:
                    std::cout << "1: Insertion at beginning" << std::endl;
                    std::cout << "2: Insertion at end" << std::endl;
                    std::cout << "3: Insertion at specific data node" << std::endl;
                    std::cout << "Enter your choice (1/2/3): ";
                    std::cin >> choice2;

                    std::cout << "Enter the value to insert: ";
                    std::cin >> value;

                    switch (choice2) {
                        case 1:
                            doubleLinkedList.insertAtBeginning(value);
                            break;
                        case 2:
                            doubleLinkedList.insertAtEnd(value);
                            break;
                        case 3:
                            std::cout << "Enter the target value after which to insert: ";
                            std::cin >> targetValue;
                            doubleLinkedList.insertAfterData(value, targetValue);
                            break;
                        default:
                            std::cout << "Invalid choice." << std::endl;
                            break;
                    }
                    break;
                case 2:
                    std::cout << "Enter the value to delete: ";
                    std::cin >> value;
                    doubleLinkedList.deleteNode(value);
                    break;
                case 3:
                    std::cout << "Doubly Linked List: ";
                    doubleLinkedList.display();
                    break;
                case 4:
                    doubleLinkedList.reverse();
                    std::cout << "Doubly Linked List reversed." << std::endl;
                    break;
                case 5:
                    std::cout << "Enter the value to seek: ";
                    std::cin >> value;
                    if (doubleLinkedList.seek(value)) {
                        std::cout << "Value found in the list." << std::endl;
                    } else {
                        std::cout << "Value not found in the list." << std::endl;
                    }
                    break;
                case 6:
                    exit(0);
                default:
                    std::cout << "Invalid choice." << std::endl;
                    break;
            }
        } else if (choice1 == 3) {
            std::cout << "Which operation you want to perform:" << std::endl;
            std::cout << "1: Insertion" << std::endl;
            std::cout << "2: Deletion" << std::endl;
            std::cout << "3: Display" << std::endl;
            std::cout << "4: Reverse" << std::endl;
            std::cout << "5: Seek" << std::endl;
            std::cout << "6: Exit" << std::endl;
            std::cout << "Enter your choice (1/2/3/4/5/6): ";
            std::cin >> choice2;

            switch (choice2) {
                case 1:
                    std::cout << "1: Insertion at beginning" << std::endl;
                    std::cout << "2: Insertion at end" << std::endl;
                    std::cout << "3: Insertion at specific data node" << std::endl;
                    std::cout << "Enter your choice (1/2/3): ";
                    std::cin >> choice2;

                    std::cout << "Enter the value to insert: ";
                    std::cin >> value;

                    switch (choice2) {
                        case 1:
                            circularLinkedList.insertAtBeginning(value);
                            break;
                        case 2:
                            circularLinkedList.insertAtEnd(value);
                            break;
                        case 3:
                            std::cout << "Enter the target value after which to insert: ";
                            std::cin >> targetValue;
                            circularLinkedList.insertAfterData(value, targetValue);
                            break;
                        default:
                            std::cout << "Invalid choice." << std::endl;
                            break;
                    }
                    break;
                case 2:
                    std::cout << "Enter the value to delete: ";
                    std::cin >> value;
                    circularLinkedList.deleteNode(value);
                    break;
                case 3:
                    std::cout << "Circular Linked List: ";
                    circularLinkedList.display();
                    break;
                case 4:
                    std::cout << "Reversing a circular linked list is not implemented." << std::endl;
                    break;
                case 5:
                    std::cout << "Enter the value to seek: ";
                    std::cin >> value;
                    if (circularLinkedList.seek(value)) {
                        std::cout << "Value found in the list." << std::endl;
                    } else {
                        std::cout << "Value not found in the list." << std::endl;
                    }
                    break;
                case 6:
                    exit(0);
                default:
                    std::cout << "Invalid choice." << std::endl;
                    break;
            }
        } else {
            std::cout << "Invalid choice." << std::endl;
        }
    }

    return 0;
}
