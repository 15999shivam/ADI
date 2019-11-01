#include <iostream>
using namespace std;

int ks(int p[], int w[], int item, int capacity)
{
    int programming[item + 1][capacity + 1];
    for (int i = 0; i <= item; i++)
    {
        for (int c = 0; c <= capacity; c++)
        {
            if (i == 0 || c == 0)
            {
                programming[i][c] = 0;
            }
            else if (w[i] <= c)
            {
                int a = p[i - 1] + programming[i - 1][c - w[i]];
                int b = programming[i - 1][c];
                programming[i][c] = a > b ? a : b;
            }
            else
            {
                programming[i][c] = programming[i - 1][c];
            }
        }
    }
    return programming[item][capacity];
}

// int ksDup(int p[], int w[], int item, int capacity)
// {
//     int programming[item + 1][capacity + 1];
//     for (int i = 0; i <= item; i++)
//     {
//         for (int c = 0; c <= capacity; c++)
//         {
//             if (i == 0 || c == 0)
//             {
//                 programming[i][c] = 0;
//             }
//             else if (w[i] <= c)
//             {
//                 int a = p[i] + programming[i][c - w[i]];
//                 // int b = programming[i - 1][c];
//                 programming[i][c] = a;
//             }
//             else
//             {
//                 programming[i][c] = programming[i - 1][c];
//             }
//         }
//     }
//     return programming[item][capacity];
// }

int main()
{
    int p[] = {12, 28, 10};
    int w[] = {2, 4, 1};

    int item = 3;
    int capacity = 6;

    cout << ks(p, w, item, capacity);
}