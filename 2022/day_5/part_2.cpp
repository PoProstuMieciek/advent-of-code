#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<stack<char>> stacks = { stack<char>({ 'Z', 'T', 'F', 'R', 'W', 'J', 'G' }), stack<char>({ 'G','W','M'}), stack<char>({'J', 'N', 'H', 'G'}), stack<char>({'J', 'R','C','N','W'}), stack<char>({'W','F','S','B','G','Q','V','M'}), stack<char>({'S','R','T','D','V','W','C'}), stack<char>({'H','B','N','C','D','Z','G','V'}), stack<char>({'S','J','N','M','G','C'}), stack<char>({'G','P','N','W','C','J','D','L'}) };
    // vector<stack<char>> stacks = { stack<char>({'Z','N'}), stack<char>({'M','C','D'}), stack<char>({'P'}) };

    int amount, from, to;
    while (scanf("move %d from %d to %d\n", &amount, &from, &to) != EOF)
    {
        vector<char> tmp;
        for (size_t i = 0; i < amount; ++i)
        {
            tmp.push_back(stacks[from - 1].top());
            stacks[from - 1].pop();
        }

        for (int i = tmp.size() - 1; i >= 0; --i)
        {
            stacks[to - 1].push(tmp[i]);
        }
    }

    string output;
    for (auto &&stack : stacks)
    {
        output += stack.top();
    }
    printf("%s\n", output.c_str());
}