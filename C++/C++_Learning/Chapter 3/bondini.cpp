#include <iostream>
using namespace std;

int main()
{
  // bondini.cpp -- using escape sequences
  cout << "\aOperation  \"HyperHype\"  is now activated!\n";
  cout << "Enter your agent code: ________\b\b\b\b\b\b\b\b";
  long code;
  cin >> code;
  cout << "\aYour entered " << code << "....\n";
  cout << "Code verified! Proceed with Plan Z3!\n";

  system("pause");
  return 0;

}