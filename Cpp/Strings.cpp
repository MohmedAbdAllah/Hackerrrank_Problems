#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    //get string 1
    string str1;
    cin>> str1;
    //get string 2
    string str2;
    cin>>str2;
    //display the string size
    cout << str1.size() <<" " <<str2.size()<<"\n";
    //display strings
    cout << str1+str2<< "\n";
    cout << str2[0] << str1.substr(1) << " "<<str1[0] << str2.substr(1);
    return 0;
}
