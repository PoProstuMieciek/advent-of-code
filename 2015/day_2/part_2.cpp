#include <bits/stdc++.h>
using namespace std;

int length_for_bow(int l, int w, int h)
{
    return l * w * h;
}

int smallest_perimiter(int l, int w, int h)
{
    return min({ l+w, w+h, l+h }) * 2;
}

int total_ribbon_needed(int l, int w, int h)
{
    return smallest_perimiter(l, w, h) + length_for_bow(l, w, h);
}

int main()
{
    int sum = 0;

    int l, w, h;
    while (scanf("%dx%dx%d\n", &l, &w, &h) != EOF)
    {
        sum += total_ribbon_needed(l, w, h);
    }

    printf("%d\n", sum);
}