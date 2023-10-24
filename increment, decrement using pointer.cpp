//increment, decrement using pointer

#include <iostream>
using namespace std;
int main() {
	float a;
	float *pt;
	a = 10.01;
	pt = &a;
	
	(*pt)++;
	cout << "\n[a]: Increment Value of A= " << a;
	
	++(*pt);
	cout << "\n[a]: Increment Value of A= " << a;
	
	(*pt)--;
	cout<<"\n[a]: Decrement Value of A= " << a;
	
	--(*pt);
	cout << "\n[a]: Decrement Value of A= "<<a;
	return 0;
}
