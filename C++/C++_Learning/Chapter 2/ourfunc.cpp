// 用户定义的函数
#include <iostream>
using namespace std;

void simon(int);
int stonetolb(int);

int main()
{
  //ourfucc.cpp
  simon(3);
  cout << "Pick an integer: ";
  int count;
  cin >> count;
  simon(count);
  cout << "Done!" << endl;


  //convert.cpp
  int stone;
  cout << "Enter the number of stone: ";
  cin >> stone;
  int pounds = stonetolb(stone);
  cout << stone << " stone is " << pounds << " pounds." << endl;

  system("pause");
  return 0;
}

void simon(int n)
{
  cout << "Simon says touch yours toes " << n << " times." << endl;
}

int stonetolb(int n)
{
  return n * 14;
}
