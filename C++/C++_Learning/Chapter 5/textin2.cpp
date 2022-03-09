// textin2.cpp -- using cin.get(char)
#include <iostream>
using namespace std;

int main()
{
    char ch;
    int count = 0;

    cout << "Enter characters; enter # to quit:\n";
    cin.get(ch);        // use the cin.get(ch) function
    while (ch != '#')
    {
        cout << ch;
        ++count;
        cin.get(ch);    // use it again
    }
    cout << endl << count << " characters read\n";

    system("pause");
    return 0; 
}
