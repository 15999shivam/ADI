#include <iostream>

using namespace std;

int MinCostPathHelper(int **a, int m, int n, int i, int j)
{

    //Base case
    if (i == m - 1 && j == n - 1)
    {
        return a[i][j];
    }

    if (i >= m || j >= n)
    {
        return INT_MAX;
    }
    //recursive calls
    int x = MinCostPathHelper(a, m, n, i + 1, j);
    int y = MinCostPathHelper(a, m, n, i + 1, j + 1);
    int z = MinCostPathHelper(a, m, n, i, j + 1);
    //logic

    return min(min(x, y), z) + a[i][j];
}

int MinCostPath(int **a, int m, int n)
{
    return MinCostPathHelper(a, m, n, 0, 0);
}

MinCostPath_memorisation_helper(int **a, int m, int n, int i, int j, int **res)
{
    // cout << "i was called" << endl;
    //Base case
    if (i == m - 1 && j == n - 1)
    {
        return a[i][j];
    }

    if (i >= m || j >= n)
    {
        return INT_MAX;
    }

    //check if value exists
    if (res[i][j] != -1)
    {
        return res[i][j];
    }
    //recursive calls

    int x = MinCostPath_memorisation_helper(a, m, n, i + 1, j, res);
    int y = MinCostPath_memorisation_helper(a, m, n, i + 1, j + 1, res);
    int z = MinCostPath_memorisation_helper(a, m, n, i, j + 1, res);
    //logic
    int result = min(min(x, y), z) + a[i][j];
    res[i][j] = result;
    return res[i][j];
}

int MinCostPath_memorisation(int **a, int m, int n)
{
    int **res = new int *[m];
    for (int i = 0; i < m; i++)
    {
        res[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            res[i][j] = -1;
        }
    }
    return MinCostPath_memorisation_helper(a, m, n, 0, 0, res);
}

int MinCostPath_dynamicProgramming(int **a, int m, int n)
{
    int **res = new int *[m];
    for (int i = 0; i < m; i++)
    {
        res[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            res[i][j] = -1;
        }
    }
    res[m - 1][n - 1] = a[m - 1][n - 1];

    //last row
    for (int i = n - 2; i >= 0; i--)
    {
        res[m - 1][i] = a[m - 1][i] + res[m - 1][i + 1];
    }
    //last colum
    //last row
    for (int i = m - 2; i >= 0; i--)
    {
        res[i][n - 1] = a[i][n - 1] + res[i + 1][n - 1];
    }

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            int x = INT_MAX, y = INT_MAX, z = INT_MAX;
            if (i + 1 < m)
                x = res[i + 1][j];
            if (i + 1 < m && j + 1 < n)
                y = res[i + 1][j + 1];
            if (j + 1 < n)
                z = res[i][j + 1];
            res[i][j] = a[i][j] + min(min(x, y), z);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return res[0][0];
}

int main()
{
    int m, n;
    cin >> m >> n;
    int **a = new int *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << MinCostPath(a, m, n) << endl;
    // cout << MinCostPath_memorisation(a, m, n) << endl;
    cout << MinCostPath_dynamicProgramming(a, m, n) << endl;
    return 0;
}