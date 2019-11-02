#include <iostream>
using namespace std;

int CoinChange(int arr[], int size, int sum)
{
    int programming[sum + 1];

    for (int n = 0; n <= size; n++)
    {
        for (int s = 0; s <= sum; s++)
        {
            if (n == 0 && s != 0)
            {
                programming[s] = 0;
            }
            else if (s == 0)
            {
                programming[s] = 1;
            }

            else if (arr[n - 1] <= s)
            {
                programming[s] = programming[s - arr[n - 1]] + programming[s];
            }
        }
    }
    for (int x = 0; x <= sum; x++)
    {
        // for (int y = 0; y <= sum; y++)
        // {
        cout << programming[x] << " ";
        // }
        // cout << endl;
    }
    return programming[sum];
}

int main()
{
    int arr[] = {1, 2, 5, 10, 20};
    int sum = 25;
    cout << CoinChange(arr, 5, sum);
}
