// ��ʼѧϰC++

# include <iostream>
# include <cmath>  // ������ѧ��
using namespace std;

int main()
{
  // myfirst.cpp
  cout << "myfirst.cpp"<<endl;

  cout << "come up and C++ me some time.";
  cout << endl;
  cout << "You won't regret it!" << endl << endl;


  // carrots.cpp
  cout << "carrots.cpp"<<endl;

  int carrots;  // ����һ������
  carrots = 5;  // ��ֵ
  cout << "I have " << carrots << " carrots." << endl;
  carrots = carrots - 1;  // ����
  cout << "Crunch, crunch. Now I have " << carrots << " carrots." << endl << endl;


  // getinfo.cpp
  cout << "getinfo.cpp"<<endl;

  cout << "How many carrots do you have?" << endl;
  cin >> carrots;
  cout << "Here are 3 more." << endl;
  carrots = carrots + 3;
  cout << "Now you have " << carrots << " carrots." << endl << endl;


  // sqrt.cpp
  cout << "sqrt.cpp"<<endl;

  double area;
  cout << "ENter the floor area, in square feet, of your home: ";
  cin >> area;
  double side;
  side = sqrt(area);
  cout << "That's the equivalent of a square " << side << " feet to the side." << endl;
  cout << "How fascinating!" << endl << endl;
  system("pause");
  return 0;
}