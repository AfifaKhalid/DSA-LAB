#include <iostream>
using namespace std;
int queue[10];
int n=10;
int front=-1;
int rear=-1;
void insert(){
	int val;
	if(rear==n-1){
		cout<<"Queue overflow"<<endl;
	}
	else{
		if(front==-1)
		front=0;
		cout<<"Insert elements in queue:"<<endl;
		cin>>val;
		rear++;
		queue[rear]=val;
	}
}
void Delete(){
	if(front==-1 || front>rear){
		cout<<"Queue underflow"<<endl;
		return;
	}
	else{
		cout<<"The deleted element is:"<<queue[front]<<endl;
		front++;
	}
}

void display(){
	if(front==-1){
		cout<<"Queue is empty"<<endl;
	}
	else{
		cout<<"Queue elements:"<<endl;
		for(int i=front; i<=rear; i++){
			cout<<queue[i]<<" ";
		}
	}
}

int main(){
	int ch;
	cout<<"1~ Inset elements to queue:"<<endl;
	cout<<"2~ Delete elements to queue:"<<endl;
	cout<<"3~ Display elements of queue:"<<endl;
	cout<<"4~ Exit!"<<endl;
	
	do{
		cout<<"\nEnter your choice:"<<endl;
		cin>>ch;
		
		switch(ch){
			case 1:insert();
			break;
			case 2:Delete();
			break;
			case 3:display();
			break;
			case 4: cout<<"Exit!"<<endl;
			break;
			default: cout<<"Invalid choice!"<<endl;
		}
	}
	while(ch!=4);
}
