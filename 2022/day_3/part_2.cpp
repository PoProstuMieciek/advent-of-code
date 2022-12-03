#include <stdio.h>
#include <string>
#include <vector>
#include <array>
using namespace std;

pair<string, string> divideString(string input)
{
    string s1, s2;

    for (size_t i = 0; i < input.size(); ++i)
    {
        if (i < input.size() / 2) s1 += input[i];
        else s2 += input[i];
    }

    return { s1, s2 };
}

int main()
{
    vector<array<string, 3>> groups;

    char backpack[65];
    size_t backpack_idx = 0;
    while (scanf("%64s", backpack) != EOF)
    {
        if (backpack_idx % 3 == 0) groups.push_back({ "", "", "" });

        groups[backpack_idx / 3][backpack_idx % 3] = backpack;

        backpack_idx++;
    }

    // for (auto &&backpacks : groups)
    // {
    //     for (auto &&b : backpacks)
    //     {
    //         printf("%s, ", b.c_str());
    //     }
    //     printf("\n");
    // }

    vector<char> badges;
    for (auto &&group : groups)
    {
        for (auto &&item : group[0])
        {
            if (group[1].find(item) != string::npos && group[2].find(item) != string::npos)
            {
                badges.push_back(item);
                break;
            }
        }
    }

    size_t sum = 0;
    for (auto &&c : badges)
    {
        if (c >= 'a' && c <= 'z') c -= 'a' - 1;
        if (c >= 'A' && c <= 'Z') c -= 'A' - 27;

        sum += c;
    }

    printf("%d\n", sum);
}