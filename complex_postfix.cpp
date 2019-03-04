#include <utility> // std :: pair lives here
#include <stack> // std :: stack lives here
#include <iostream>
using namespace std ; // can now refer to std :: pair as pair

int main()
{
    char VBUS;
    int r1;
    int r2;
    char op;
    
    while (true) 
    {
        cin >> VBUS;
        if (VBUS == 'V')
        {
            cin >> r1 >> r2;
            pair<int,int> currentPair(r1,r2);
        }
        else if (VBUS == 'B')
        {
            cin >> op;
        }
        else if (VBUS == 'U')
        {
            cin >> op;
        }
        else if (VBUS == 'S')
        {
            break;
        }
    }

}