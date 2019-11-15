#include <iostream>
using namespace std;

int minStepsToOne(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else
    {
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        a = minStepsToOne(n - 1);
        if (n % 2 == 0)
        {
            b = minStepsToOne(n / 2);
        }
        if (n % 3 == 0)
        {
            c = minStepsToOne(n / 3);
        }
        return 1 + min(min(a, b), c);
    }
}

int minStepsToOneMemorisation_helper(int n, int *arr)
{
    if (n <= 1)
    {
        arr[1] = 0;
        return 0;
    }
    else
    {
        if (arr[n] != -1)
            return arr[n];
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        a = minStepsToOneMemorisation_helper(n - 1, arr);
        if (n % 3 == 0)
        {
            b = minStepsToOneMemorisation_helper(n / 3, arr);
        }
        if (n % 2 == 0)
        {
            c = minStepsToOneMemorisation_helper(n / 2, arr);
        }
        arr[n] = 1 + min(min(a, b), c);
        return arr[n];
    }
}

int minStepsToOneMemorisation(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    int ans = minStepsToOneMemorisation_helper(n, arr);
    // cout << endl;
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    return ans;
}

int minStepsToOneDynamicProgramming(int n)
{
    int *arr = new int[n + 1];
    arr[1] = 0;
    // cout << endl;
    for (int i = 2; i <= n; i++)
    {
        int a = arr[i - 1];
        int b = INT_MAX, c = INT_MAX;
        if (i % 2 == 0)
        {
            b = arr[i / 2];
        }
        if (i % 3 == 0)
        {
            c = arr[i / 3];
        }
        arr[i] = 1 + min(min(a, b), c);
        // cout << arr[i] << " ";
    }
    // cout << endl;
    return arr[n];
}

int main()
{
    int n = 7;
    cout << minStepsToOne(n) << endl;
    cout << minStepsToOneMemorisation(n) << endl;
    cout << minStepsToOneDynamicProgramming(n) << endl; //dp stud h bhai
    return 0;
}