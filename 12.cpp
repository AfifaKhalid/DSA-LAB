#include <iostream>
using namespace std;

int main() {
    int tot, i;

    cout << "Enter the array size: ";
    cin >> tot;
    long int *id = new long int[tot];
    float *marks = new float[tot];

    for (i = 0; i < tot; i++) {
        cout << "Enter ID and Marks of Student No. " << (i + 1) << ": ";
        cin >> id[i] >> marks[i];
    }

    cout << "\n\nStudent ID\t\tStudent Mark\n";
    for (i = 0; i < tot; i++) {
        cout << id[i] << "\t\t" << marks[i] << "\n";
    }

    delete[] id;
    delete[] marks;

    return 0;
}

