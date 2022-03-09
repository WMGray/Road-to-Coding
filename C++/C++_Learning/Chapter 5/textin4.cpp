// textin4.cpp -- reading chars with cin.get()
#include <iostream>
using namespace std;

int main(void)
{
    int ch;                         // should be int, not char
    int count = 0;

    while ((ch = cin.get()) != EOF) // test for end-of-file
    {
        cout.put(char(ch));
        ++count;
    }
    cout << endl << count << " characters read\n";

    system("pause");
	  return 0; 
}
