#include <utility> // std :: pair lives here
#include <stack> // std :: stack lives here
#include <iostream>
using namespace std; // can now refer to std :: pair as pair

int main()
{
    char VBUS;
    long long r1;
    long long r2;
    char op;
    stack<pair<long long,long long>> s;
    long long real1 = 0;
    long long imaginary1 = 0;
    long long real2 = 0;
    long long imaginary2 = 0;
    long long realSum = 0;
    long long imaginarySum = 0;
    while (true) 
    {
        cin >> VBUS;
        if (VBUS == 'V')
        {

            cin >> r1 >> r2;

            pair<long long,long long> currentPair(r1,r2);
            
            s.push(currentPair);
        }
        else if (VBUS == 'B')
        {

            cin >> op;
            if (op == '+')
            {
                real1 = s.top().first;
                imaginary1 = s.top().second;
                s.pop();
                real2 = s.top().first;
                imaginary2 = s.top().second;
                s.pop();
                realSum = real1 + real2;
                imaginarySum = imaginary1 + imaginary2;
                pair<long long,long long> answer(realSum,imaginarySum);
                s.push(answer);
            }
            else if (op == '*')
            {
                real1 = s.top().first;
                imaginary1 = s.top().second;
                s.pop();
                real2 = s.top().first;
                imaginary2 = s.top().second;
                s.pop();
                realSum = (real1 * real2) - (imaginary1 * imaginary2);
                imaginarySum = (imaginary1 * real2) + (imaginary2 * real1);
                pair<long long,long long> answer(realSum,imaginarySum);
                s.push(answer);
            }
            else if (op == '-')
            {
                real1 = s.top().first;
                imaginary1 = s.top().second;
                s.pop();
                real2 = s.top().first;
                imaginary2 = s.top().second;
                s.pop();
                realSum = real2 - real1;
                imaginarySum = imaginary2 - imaginary1;
                pair<long long,long long> answer(realSum,imaginarySum);
                s.push(answer);
            }
        }
        else if (VBUS == 'U')
        {
            cin >> op;
            if (op == '-')
            {
                s.top().first = s.top().first*-1;
                s.top().second = s.top().second*-1;
            }
            else if (op == 'c')
            {
                s.top().second = s.top().second*-1;
            }
        }
        else if (VBUS == 'S')
        {
            cout << s.top().first << " " << s.top().second << " " << endl;
            break;
        }
    }

}