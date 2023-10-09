#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void displayLinkedList(Node* head) {
    Node* ptr = head;
    cout << "The linked list is: "<<endl;
    while (ptr !=NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl<<endl;
    ptr = head;
    cout << "head address: " << &head << endl;
    cout<<"---------------------------------------"<<endl;
    cout << "head content: " << head << endl;
    cout<<"---------------------------------------"<<endl;
    while (ptr != NULL) {
        cout << "**ptr address:* " << &ptr << endl;
        cout << "ptr content: " << ptr << endl;
        cout << "ptr->data: " << ptr->data << endl;
        cout << "ptr: " << ptr << endl;
        cout << "ptr->next: " << ptr->next << endl;
        ptr = ptr->next;
    }
}
int main() {
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;

    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 20;
    third->next = fourth;

    fourth->data = 30;
    fourth->next = NULL;
    displayLinkedList(head);
    delete head;
    delete second;
    delete third;
    delete fourth;
    return 0;
}

