#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};

class CircularLL {
private:
    Node* tail;

public:
    CircularLL() {
        tail =NULL;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        
        if (tail == NULL) {
            tail = newNode;
            newNode->next = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode; 
        }
    }

    void deleteAtEnd() {
        if (tail == NULL) {
            cout << "The list is empty. Deletion is not possible." <<endl;
            return;
        }

        if (tail->next == tail) {
            delete tail;
            tail = NULL;
        } else {
            Node* current = tail->next;
            while (current->next != tail) {
                current = current->next;
            }
            current->next = tail->next;
            delete tail;
            tail = current;
        }
    }
    void display() {
        if (tail == NULL) {
            cout << "The list is empty." <<endl;
            return;
        }

        Node* current = tail->next;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != tail->next);
        cout<<endl;
    }
};

int main() {
    CircularLL n;

    n.insertAtEnd(1);
    n.insertAtEnd(2);
    n.insertAtEnd(3);
    n.insertAtEnd(4);
    n.insertAtEnd(5);


    cout << "Circular Linked List: ";
    n.display();

    n.deleteAtEnd();
    cout << "After deletion: ";
    n.display();

    return 0;
}
