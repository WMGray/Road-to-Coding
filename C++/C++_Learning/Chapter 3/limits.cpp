#include <iostream>
#include <climits>
using namespace std;

int main()
{
  // limits.cpp
  int n_int = {INT_MAX};
  short n_short = SHRT_MAX;
  long n_long = LONG_MAX;
  long long n_longlong = LLONG_MAX;
  int ABC{};

  cout << "int is " << sizeof(int) << " bytes" << endl;
  cout << "short is " << sizeof(short) << " bytes" << endl;
  cout << "long is " << sizeof(long) << " bytes" << endl;
  cout << "long long is " << sizeof(long long) << " bytes" << endl;
  cout << endl ;

  cout << "Maximun values:" << endl;
  cout << "int :" << n_int << endl;
  cout << "short :" << n_short << endl;
  cout << "long :" << n_long << endl;
  cout << "long long :" << n_longlong << endl;

  cout << "Minimum values:" << endl;
  cout << "int :" << INT_MIN << endl;
  cout << "short :" << SHRT_MIN << endl;
  cout << "long :" << LONG_MIN << endl;
  cout << "long long :" << LLONG_MIN << endl; 

  cout << endl;
  cout << "Bits per byte:" << CHAR_BIT << endl;

  cout << "ABC{}:  ABC = " << ABC << endl;
  system("pause");
  return 0;
}