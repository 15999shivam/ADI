#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printDFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] == 1)
        {
            if (visited[i])
                continue;
            printDFS(edges, n, i, visited);
        }
    }
}

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            printDFS(edges, n, i, visited);
    }
    delete[] visited;
}

void print(vector<int> v)
{
    cout << "[ ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "]\n";
}

vector<int> getDFSpath_helper(int **edges, int n, int start, int end, bool *visited)
{
    vector<int> res;
    visited[start] = true;
    if (start == end)
    {
        res.push_back(start);
        return res;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (edges[start][i] == 1)
            {
                if (!visited[i])
                {
                    res = getDFSpath_helper(edges, n, i, end, visited);
                }
            }
            if (res.size() != 0)
            {
                // print(res);
                res.push_back(start);
                return res;
            }
        }
        return res;
    }
}

vector<int> getDFSpath(int **edges, int n, int start, int end)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    // vector<int> res = getDFSpath_helper(edges, n, start, end, visited);
    // for (int i = 0; i < n; i++)
    //     cout << visited[i] << " ";
    // cout << endl;
    return res;
}

int main()
{
    int n;
    int e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    //DFS
    cout << "DFS" << endl;
    DFS(edges, n);

    //PATH
    cout << "PATH" << endl;
    while (true)
    {
        int start, end;
        cin >> start >> end;
        vector<int> path = getDFSpath(edges, n, start, end);
        cout << "Path: ";
        for (int i = 0; i < path.size() - 1; i++)
        {
            cout << path[i] << " <- ";
        }
        cout << path[path.size() - 1] << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete edges[i];
    }
    delete edges;
}