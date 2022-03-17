// arrtemp.cpp -- using template functions with array template
#include <iostream>
#include <array>
#include <string>
using namespace std;

template <class T, size_t n>
void display(const array<T, n> & ar);
int main()
{
	array<int, 5> ai = {1,2,3,4,5}; //,6,7,8,9,22};
	array<string, 5> as =
	{
		"string under construction",
		"stupid string indeed",
		"there's nothing to see",
		"nothing to do",
		"but enjoy all that is"
	};
	display(ai);
	display(as);
	
  system("pause");
	return 0;
}
template <class T, size_t n>
void display(const array<T,  n> & ar)
{
	for (int i = 0; i < 5; i++)
		cout << ar[i] << endl;
}