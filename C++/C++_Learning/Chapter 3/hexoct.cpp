#include <iostream>
using namespace std;

int main()
{
  // hexcot.cpp -- show hex and octal conversion
  int chest = 42
    , waist = 0x42   // hexadecimal
    , inseam = 042;  // octal

  cout << "Monsieur cuts a striking figure!\n";
  cout << "chest = " << chest << " (42 in decimal)\n";
  cout << "waist = " << waist << " (0x42 in hex)\n";
  cout << "inseam = " << inseam << " (042 in octal)\n";

  // hexoct2.cpp --display values in hex and octal
  chest = waist = inseam = 42;
  cout << "Monsieur cuts a striking figure!\n";
  cout << "chest = " << chest << " (decimal for 42)\n";
  cout << hex; 
  cout << "waist = " << waist << " (hexadecimal for 42)\n";
  cout << oct;
  cout << "inseam = " << inseam << " (octal for 42)\n";
  system("pause");
  return 0; 
}