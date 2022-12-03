#include <stdio.h>
#include <string>
#include <vector>
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
    vector<pair<string, string>> backpacks;

    char backpack[65];
    while (scanf("%64s", backpack) != EOF)
    {
        backpacks.push_back(divideString(backpack));
    }

    vector<string> backpacks_filtered;
    for (auto &&backpack : backpacks)
    {
        string in_both;

        for (auto &&c : backpack.first)
        {
            if (backpack.second.find(c) != string::npos && in_both.find(c) == string::npos)
            {
                in_both += c;
            }
        }

        backpacks_filtered.push_back(in_both);
    }

    if (backpacks_filtered.size() < 1) return 1;

    // for (auto &&backpack : backpacks_filtered)
    // {
    //     printf("debug: %s\n", backpack.c_str());
    // }

    size_t sum = 0;
    for (auto &&backpack : backpacks_filtered)
    {
        for (auto &&c : backpack)
        {
            if (c >= 'a' && c <= 'z') c -= 'a' - 1;
            if (c >= 'A' && c <= 'Z') c -= 'A' - 27;

            sum += c;
        }
    }

    printf("%d\n", sum);
}