// ifelse.cpp -- using the if else statement
#include <iostream>
using namespace std;

int main()
{
    char ch;

    cout << "Type, and I shall repeat.\n";
    cin.get(ch);
    while (ch != '.')
    {
        if (ch == '\n')
            cout << ch;     // done if newline
        else
            cout << ++ch;   // done otherwise
        cin.get(ch);
    }
// try ch + 1 instead of ++ch for interesting effect
    cout << "\nPlease excuse the slight confusion.\n";

    system("pause");
    return 0;
}
