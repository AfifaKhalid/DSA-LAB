#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = NULL;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

class MyStack {
public:
    struct StackNode {
        int data;
        StackNode* next;

        StackNode(int val) {
            data = val;
            next = NULL;
        }
    };

    StackNode* top;

    MyStack() {
        top = NULL;
    }

    void push(int val) {
        StackNode* newNode = new StackNode(val);
        if (!top) {
            top = newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
    }

    int pop() {
        if (!top) {
            cerr << "Error: Stack is empty" << endl;
            return -1;
        }
        int val = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    int peek() {
        if (!top) {
            cerr << "Error: Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

bool isPalindrome(Node* head) {
    MyStack stack;
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        stack.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast) {
        slow = slow->next;
    }

    while (slow) {
        if (stack.pop() != slow->data) {
            return false;
        }
        slow = slow->next;
    }

    return true;
}

int main() {
    SinglyLinkedList sll;
    int n;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    cout << "Enter the elements one by one: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        sll.append(element);
    }

    cout << "Linked List: ";
    sll.display();

    if (isPalindrome(sll.head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}

