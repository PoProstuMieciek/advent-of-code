#include <iostream>
using namespace std;

int main()
{
    string data;
    cin >> data;

    int output = 0;

    for (size_t i = 0; i < data.size(); ++i)
    {
        if (data[i] == '(') ++output;
        if (data[i] == ')') --output;

        if (output < 0)
        {
            cout << i + 1 << endl;
            break;
        }
    }
}