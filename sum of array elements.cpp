#include <iostream>
using namespace std;
#define MAX_SIZE 5
int main() {
int var[] = {10, 20, 30, 40, 50};
int i = 0, sum = 0;
int *pt;
pt = &var[0];
while (i < MAX_SIZE) {
i++;
sum=sum + *pt;
pt++;
}
cout << "Sum of Array:"<<sum;
return 0; 
}
