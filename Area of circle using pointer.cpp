//Area of circle using pointer

#include <iostream>
using namespace std;
void area_of_circle(float *value, float *result) {
*result=3.14 *(*value) *(*value);
}
	int main() {
		float radius, area;
		cout << "Area of Circle Using Pointer and Functions\n";
		cout << "\nEnter the radius of Circle: ";
		cin>>radius;
		area_of_circle(&radius, &area);
		cout << "\nArea of Circle :"<< area;
	return 0;
}
