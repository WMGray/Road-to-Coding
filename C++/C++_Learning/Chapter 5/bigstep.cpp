// bigstep.cpp -- count as directed
#include <iostream>
using namespace std;

int main()
{
    cout << "Enter an integer: ";
    int by;
    cin >> by;
    cout << "Counting by " << by << "s:\n";
    for (int i = 0; i < 100; i = i + by)
        cout << i << endl;
    
    system("pause");
    return 0;
}
