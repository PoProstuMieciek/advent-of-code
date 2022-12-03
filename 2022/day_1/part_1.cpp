#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> split_string(string input, string delimeter)
{
    vector<string> pieces;
    size_t pos = 0;
    string token;

    while((pos = input.find(delimeter)) != string::npos)
    {
        token = input.substr(0, pos);
        pieces.push_back(token);
        input.erase(0, pos + delimeter.length());
    }
    pieces.push_back(input);

    return pieces;
}

int main()
{
    ifstream file("data/example.txt");
    stringstream buffer;
    buffer << file.rdbuf();

    string data = buffer.str();

    auto elves = split_string(data, "\n\n");

    vector<int> calories;
    for (int i = 0; i < elves.size(); ++i)
    {
        auto elf = split_string(elves[i], "\n");

        int sum = 0;
        for (string item : elf)
        {
            int item_int = atoi(item.c_str());

            sum += item_int;
        }

        calories.push_back(sum);
    }

    sort(calories.begin(), calories.end());
    reverse(calories.begin(), calories.end());

    cout << calories[0] << endl;

    return 0;
}