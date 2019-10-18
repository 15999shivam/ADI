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

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{

    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 12};
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << sizeof(arr);
    return 0;
}