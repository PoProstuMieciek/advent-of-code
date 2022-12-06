#include <bits/stdc++.h>
using namespace std;

int area_of_smallest_side(int l, int w, int h)
{
    return min({ l*w, w*h, l*h });
}

int area(int l, int w, int h)
{
    return 2*l*w + 2*w*h + 2*h*l;
}

int total_paper_needed(int l, int w, int h)
{
    return area(l, w, h) + area_of_smallest_side(l, w, h);
}

int main()
{
    int sum = 0;

    int l, w, h;
    while (scanf("%dx%dx%d\n", &l, &w, &h) != EOF)
    {
        sum += total_paper_needed(l, w, h);
    }

    printf("%d\n", sum);
}