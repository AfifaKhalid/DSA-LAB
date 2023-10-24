#include <iostream>
using namespace std;

int main() {
    int *ptr;
    int arr[5];
    int i;

    cout << "Enter any five numbers: ";

    for (i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    ptr = arr; // Assign the address of the first element of the array to the pointer.

    for (i = 0; i < 5; i++) {
        cout << "\n\nptr = " << *ptr;
        cout << "\narr[" << i << "] = " << arr[i];
        ptr++; // Move the pointer to the next element.
    }

    cout << endl;
    return 0;
}
