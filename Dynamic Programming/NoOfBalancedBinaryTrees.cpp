#include <iostream>
#include <math.h>
using namespace std;

int NoOfBalancedBinaryTrees(int h)
{
    if (h <= 1)
    {
        return 1;
    }
    else
    {
        int mod = (int)(pow(10, 9)) + 7;
        int x = NoOfBalancedBinaryTrees(h - 1);
        int y = NoOfBalancedBinaryTrees(h - 2);
        int temp1 = (int)(((long long)(x)*x) % mod);
        int temp2 = (int)(((long long)(x)*y * 2) % mod);
        int ans = (temp1 + temp2) % mod;
        return ans;
    }
}
int NoOfBalancedBinaryTrees_memorization_helper(int h, int *arr)
{
    if (h <= 1)
    {
        return 1;
    }
    else
    {
        if (arr[h] != -1)
        {
            return arr[h];
        }
        else
        {
            int x, y;
            int mod = (int)(pow(10, 9)) + 7;
            x = NoOfBalancedBinaryTrees_memorization_helper(h - 1, arr);
            y = NoOfBalancedBinaryTrees_memorization_helper(h - 2, arr);
            int temp1 = (int)(((long long)(x)*x) % mod);
            int temp2 = (int)(((long long)(x)*y * 2) % mod);
            int ans = (temp1 + temp2) % mod;
            arr[h] = ans;
            return arr[h];
        }
    }
}
int NoOfBalancedBinaryTrees_memorization(int h)
{
    int *arr = new int[h + 1];
    for (int i = 0; i <= h; i++)
    {
        arr[i] = -1;
    }
    return NoOfBalancedBinaryTrees_memorization_helper(h, arr);
}

int NoOfBalancedBinaryTrees_dynamic_programming(int h)
{
    int *arr = new int[h + 1];
    for (int i = 0; i <= h; i++)
    {
        arr[i] = -1;
    }
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <= h; i++)
    {
        int x, y;
        int mod = (int)(pow(10, 9)) + 7;
        x = arr[i - 1];
        y = arr[i - 2];
        int temp1 = (int)(((long long)(x)*x) % mod);
        int temp2 = (int)(((long long)(x)*y * 2) % mod);
        int ans = (temp1 + temp2) % mod;
        arr[i] = ans;
    }
    return arr[h];
}

int main()
{
    int n = 6;
    // cin >> n;
    cout << NoOfBalancedBinaryTrees(n) << endl;
    cout << NoOfBalancedBinaryTrees_memorization(n) << endl;
    cout << NoOfBalancedBinaryTrees_dynamic_programming(n) << endl;
    return 0;
}