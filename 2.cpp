//Addition and subtraction using pointer

#include<iostream>
using namespace std;

    int add(int a, int b)
    {return a+b;}
    
    int subtract(int a, int b)
    {return a-b;}

	int main(){
		int(*ptr)(int,int);
		ptr=add;
		cout<<"Addition:"<<ptr(5,3)<<endl;
		
		ptr=subtract;
		cout<<"Subtraction:"<<ptr(5,3)<<endl;
		
    return 0;
}

