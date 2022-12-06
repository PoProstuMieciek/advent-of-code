#include <iostream>
using namespace std;

int main()
{
    string data;
    cin >> data;

    int output = 0;

    for (auto &&c : data)
    {
        if (c == '(') ++output;
        if (c == ')') --output;
    }

    cout << output << endl;
}