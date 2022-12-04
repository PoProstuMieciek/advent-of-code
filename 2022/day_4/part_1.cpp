#include <stdio.h>
#include <vector>
#include <array>
using namespace std;

bool is_in_range(int t, int x, int y)
{
    return x <= t && t <= y;
}

bool does_overlap(int x1, int y1, int x2, int y2)
{
    return (is_in_range(x1, x2, y2) && is_in_range(y1, x2, y2)) || (is_in_range(x2, x1, y1) && is_in_range(y2, x1, y1));
}

int main()
{
    size_t count = 0;

    int x1, y1, x2, y2;
    while (scanf("%d-%d,%d-%d\n", &x1, &y1, &x2, &y2) != EOF)
    {
        count += does_overlap(x1, y1, x2, y2);
    }

    printf("%d\n", count);
}