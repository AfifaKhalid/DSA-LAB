//print the value and address of num using pointer

#include<iostream>
using namespace std;
int main()
{
    int num=10;
    int* ptr=&num;
    
    cout<<"Value of num="<<num<<endl;
    cout<<"Address of num="<<&num<<endl;
    cout<<"Value of num using pointer="<<*ptr<<endl;

    return 0;
}

