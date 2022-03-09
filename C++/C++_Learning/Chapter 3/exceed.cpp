// wxceed.cpp -- exceeding some integer limits
#include <iostream>
#include <climits>
#define ZERO 0
using namespace std;

int main()
{
  short sam = SHRT_MAX;
  unsigned short sue = sam;

  cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited." << endl;
  sam++;
  sue++;
  cout << " Add $1 to each account." << endl;
  cout << "Now Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited. " << endl;
  cout << "Poor Sam" << endl;
  sam = sue = ZERO;
  cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited. " << endl;
  cout << "Take $1 from each account." << endl;
  sam--;
  sue--;
  cout << "Now Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited." << endl;
  cout << "Lucky Sue" << endl;
  system("pause");
  return 0;
}