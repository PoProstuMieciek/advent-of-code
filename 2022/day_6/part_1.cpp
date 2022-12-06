#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    string stream;
    cin >> stream;

    queue<char> last_four;

    size_t bytes_read;
    for (bytes_read = 0; bytes_read < stream.size(); ++bytes_read)
    {
        if (last_four.size() == 4)
        {
            queue<char> q_copy = last_four;
            int stats[26] = { 0 };

            while (!q_copy.empty())
            {
                stats[q_copy.front() - 'a']++;
                q_copy.pop();
            }

            bool all_unique = true;
            for (size_t i = 0; i < 26; i++)
            {
                if (stats[i] > 1) all_unique = false;
            }

            if (all_unique)
            {
                cout << bytes_read << endl;
                break;
            }

            last_four.pop();
        }

        last_four.push(stream[bytes_read]);
    }
}