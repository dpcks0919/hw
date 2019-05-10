// On my honour, I pledge that I have neither received not provided improper
//assistance in the completion of this assignment
//Signed: 김예찬 Section: 02 Student Number: 21600120

#include <iostream>
#include <string>
using namespace std;

int main () {
  string str;

  for(int i=1; i > 0 ; i++ ){
  cout << "Enter a name: ";
  getline(cin, str);
  if (str.length() > 0)
    cout << "Hello " << str << "!\n";

  else
  {
    cout << "Hello World!";
    return 0;
  }
}
}
