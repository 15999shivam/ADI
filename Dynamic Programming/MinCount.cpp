#include <iostream>
#include <math.h>
using namespace std;

int minCount(int n)
{
    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    if (n <= 3)
        return n;

    else
    {
        int min = INT_MAX;
        for (int i = 1; i * i <= n; i++)
        {
            int res = minCount(n - (i * i));
            if (res < min)
            {
                min = res;
            }
        }
        return min + 1;
    }
}
int minCountMemorisation_helper(int n, int *arr)
{
    if (n <= 3)
    {
        arr[n] = n;
        return n;
    }
    if (sqrt(n) - floor(sqrt(n)) == 0)
    {
        arr[n] = 1;
        return 1;
    }
    int min = n;
    for (int i = 1; i * i <= n; i++)
    {
        int res;
        if (arr[n - (i * i)] != -1)
            res = arr[n - (i * i)];
        else
            res = minCountMemorisation_helper(n - (i * i), arr);
        if (min > res)
            min = res;
    }
    arr[n] = min + 1;
    return arr[n];
}
int minCountMemorisation(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    return minCountMemorisation_helper(n, arr);
}

int minCountDynamicProgramming(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;

    for (int i = 4; i <= n; i++)
    {
        arr[i] = i;
        for (int x = 1; (x * x) <= i; x++)
        {
            int res = 1 + arr[i - (x * x)];
            if (res < arr[i])
                arr[i] = res;
        }
    }
    return arr[n];
}

int main()
{
    int n = 40;
    cout << minCount(n) << endl;
    cout << minCountMemorisation(n) << endl;
    cout << minCountDynamicProgramming(n) << endl;
    return 0;
}