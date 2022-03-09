#include <iostream>
using namespace std;

int main()
{
  //chartype.cpp -- the char type
  char ch;
  cout << "Enter a character: ";
  cin >> ch;
  cout << "Hola!";
  cout << "Thank you for entering " << ch << " character." << endl;

  // morechar.cpp -- the char type and int type contrasted
  ch = 'M';
  int i = ch;
  cout << "The ASCII code for " << ch << " is " << i << endl;

  cout << "Add one to the character code: " << endl;
  ch = ch + 1;
  i = ch;
  cout << "The ASCII code for " << ch << " is " << i << endl;

  // using the cout,put() member function to display the character
  cout << "Displaying the character ch using put() member function" << endl;
  cout.put(ch);
  //using cout.put() to display a char constant
  cout.put('!');

  cout << endl << "Done" << endl;
  
  system("pause");
  return 0;

}