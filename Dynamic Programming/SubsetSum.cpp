#include <iostream>
using namespace std;

int SubSetSum(int arr[], int size, int k)
{
    int programming[size + 1][k + 1];
    for (int n = 0; n <= size; n++)
    {
        for (int s = 0; s <= k; s++)
        {
            if (n == 0 && s != 0)
            {
                programming[n][s] = 0;
            }
            else if (s == 0)
            {
                programming[n][s] = 1;
            }
            else if (arr[n] > s)
            {
                programming[n][s] = programming[n - 1][s];
            }
            else
            {
                programming[n][s] = programming[n - 1][s - arr[n]] || programming[n - 1][s];
            }
        }
    }
    return programming[size][k];
}

int main()
{
    int arr[] = {6, 3, 2, 1};
    cout << SubSetSum(arr, 4, 5);
}