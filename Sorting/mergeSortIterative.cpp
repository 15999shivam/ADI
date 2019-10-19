#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int ar2[r + 1];
    for (int n = l; n <= r; n++)
    {
        ar2[n] = arr[n];
        cout << l << " " << m << " " << r << " " << ar2[n] << endl;
    }
    cout << endl;
    int i = l;
    int j = m + 1;
    int k = l;
    while (i <= m && j <= r)
    {
        if (ar2[i] <= ar2[j])
        {
            arr[k] = ar2[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = ar2[j];
            k++;
            j++;
        }
    }
    while (i <= m)
    {
        arr[k] = ar2[i];
        k++;
        i++;
    }
    while (j <= r)
    {
        arr[k] = ar2[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int n)
{
    int p, l, h, mid, i;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 <= n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(arr, l, mid, h);
        }
    }
    if (p / 2 < n)
        merge(arr, 0, p / 2 - 1, n);
}

int main()
{

    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 12};
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << sizeof(arr);
    return 0;
}