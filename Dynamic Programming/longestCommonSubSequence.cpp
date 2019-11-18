#include <iostream>
using namespace std;

int lcs(string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }
    if (s[0] == t[0])
    {
        return 1 + lcs(s.substr(1), t.substr(1));
    }
    else
    {
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        return max(a, b);
    }
}

int lcs_memorisation_helper(string s, string t, int **arr)
{
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }
    int m = s.size();
    int n = t.size();
    if (arr[m][n] != -1)
        return arr[m][n];
    if (s[0] == t[0])
    {
        int res = 1 + lcs_memorisation_helper(s.substr(1), t.substr(1), arr);
        arr[m][n] = res;
        return arr[m][n];
    }
    int a = lcs_memorisation_helper(s.substr(1), t, arr);
    int b = lcs_memorisation_helper(s, t.substr(1), arr);
    int res = max(a, b);
    arr[m][n] = res;
    return arr[m][n];
}

int lcs_memorisation(string s, string t)
{
    int **arr = new int *[s.size() + 1];
    for (int i = 0; i <= s.size(); i++)
    {
        arr[i] = new int[t.size() + 1];
        for (int j = 0; j <= t.size(); j++)
        {
            arr[i][j] = -1;
        }
    }
    return lcs_memorisation_helper(s, t, arr);
}

int lcs_DP(string s, string t)
{
    int **arr = new int *[s.size() + 1];
    for (int i = 0; i <= s.size(); i++)
    {
        arr[i] = new int[t.size() + 1];
    }
    int m = s.size();
    int n = t.size();
    for (int i = 0; i <= m; i++)
    {
        arr[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        arr[0][j] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                arr[i][j] = 1 + arr[i - 1][j - 1];
            }
            else
            {
                arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
            }
            // cout << arr[i][j] << " ";
        }
        // cout << endl;
    }

    return arr[m][n];
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << lcs(s, t) << endl;
    cout << lcs_memorisation(s, t) << endl;
    cout << lcs_DP(s, t) << endl;
    return 0;
}