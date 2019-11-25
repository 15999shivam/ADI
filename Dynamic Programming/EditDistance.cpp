#include <iostream>
using namespace std;

int EditDistance(string s, string t)
{
    //base case
    if (s.size() == 0 || t.size() == 0)
    {
        return s.size() > t.size() ? s.size() : t.size();
    }

    //recursive calls
    if (s[0] == t[0])
    {
        return EditDistance(s.substr(1), t.substr(1));
    }
    else
    {
        int i, u, d;
        i = EditDistance(s.substr(1), t);
        u = EditDistance(s.substr(1), t.substr(1));
        d = EditDistance(s, t.substr(1));
        return 1 + min(i, min(u, d));
    }
}

int EditDistance_memorisation_helper(string s, string t, int **arr)
{
    //base case
    if (s.size() == 0 || t.size() == 0)
    {
        return s.size() > t.size() ? s.size() : t.size();
    }
    if (arr[s.size()][t.size()] != -1)
    {
        return arr[s.size()][t.size()];
    }
    //recursive calls
    if (s[0] == t[0])
    {
        int res = EditDistance(s.substr(1), t.substr(1));
        arr[s.size()][t.size()] = res;
        return arr[s.size()][t.size()];
    }
    int i, u, d;
    i = EditDistance(s.substr(1), t);
    u = EditDistance(s.substr(1), t.substr(1));
    d = EditDistance(s, t.substr(1));
    int res = 1 + min(i, min(u, d));
    arr[s.size()][t.size()] = res;
    return arr[s.size()][t.size()];
}

int EditDistance_memorisation(string s, string t)
{
    int **arr = new int *[s.size()];
    for (int i = 0; i < s.size() + 1; i++)
    {
        arr[i] = new int[t.size() + 1];
        for (int j = 0; j < t.size() + 1; j++)
        {
            arr[i][j] = -1;
        }
    }
    return EditDistance_memorisation_helper(s, t, arr);
}

int EditDistance_DP(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **arr = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        arr[i] = new int[n + 1];
    }
    for (int i = 0; i < m + 1; i++)
    {
        arr[i][0] = i;
    }
    for (int i = 0; i < n + 1; i++)
    {
        arr[0][i] = i;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s[m - 1] == t[n - j])
                arr[i][j] = arr[i - 1][j - 1];
            else
            {
                arr[i][j] = min(arr[i - 1][j], min(arr[i - 1][j - 1], arr[i][j - 1])) + 1;
            }
        }
    }
    return arr[m][n];
}

int main()
{
    string s = "nldfnsdlfkd";
    string t = "fhddlnfdskfn";
    cout << EditDistance(s, t) << endl;
    cout << EditDistance_memorisation(s, t) << endl;
    cout << EditDistance_DP(s, t) << endl;
    return 0;
}