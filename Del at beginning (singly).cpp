#include<iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;

public:
    Node* head;
    Node() {
        head = NULL;
    }

    void addToEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }

    void deleteAtBeg() {
        if (head == NULL) {
            cout << "Linked list is empty!" << endl;
        }
        else {
            Node* temp = head;
            if (temp->next == NULL) {
                head = NULL;
            }
            else {
                head = temp->next;
            }
            delete temp;
        }
    }

    void display() {
        Node* ptr = head;
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main() {
    Node n;
    n.display();

    n.addToEnd(12);
    n.addToEnd(22);
    n.addToEnd(15);
    n.addToEnd(32);
    n.addToEnd(95);

    n.display();

    n.deleteAtBeg();
    n.display();

    return 0;
}

