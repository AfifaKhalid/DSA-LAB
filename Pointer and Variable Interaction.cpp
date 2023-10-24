#include<iostream>
using namespace std;
int main()
{
	int num = 10;
	int val;
	int *iptr;
	iptr = &num;
	val= *iptr;

		cout<<"num  = "<<num<<endl;
		cout<<"val  = "<<val<<endl;
		cout<<"iptr = "<<iptr<<endl;
		cout<<"*iptr= "<<*iptr<<endl;
		cout<<endl;

	return 0;
}
