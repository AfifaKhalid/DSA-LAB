//vowels and consonants in a string

#include <iostream>
using namespace std;
int main() {
    char str[20], *pt;
    int i = 0, c = 0;
    
    cout << "Enter any string in small letters [below 20 chars]: ";
    cin >> str; 
    
    pt = str;
    
    while (*pt != '\0') {
        if (*pt == 'a' || *pt == 'i' || *pt == 'o' || *pt == 'u')
		{
		     c++;
        }
        i++;
        pt++;
    }
    
    cout << "\nLength of String: " << i;
    cout << "\nVowels Count In the String: " << c;
    cout << "\nConsonant Count in the String: " << (i - c);
    return 0;
}

