#include <iostream>
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

void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << endl;
        for (int i = 0; i < n; i++)
        {
            if (i == currentVertex)
                continue;
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            printBFS(edges, n, i, visited);
    }
    delete[] visited;
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

bool hasPath_helper(int **edges, int n, int sv, bool *visited, int e)
{
    // cout << sv << endl;
    if (sv == e)
        return true;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] == 1)
        {
            if (visited[i])
                continue;
            bool res = hasPath_helper(edges, n, i, visited, e);
            if (res == true)
                return true;
        }
    }
    return false;
}

bool hasPath(int **edges, int n, int edge1, int edge2)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    return hasPath_helper(edges, n, edge1, visited, edge2);
    delete[] visited;
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

    //BFS
    cout << "BFS" << endl;
    BFS(edges, n);

    //hasPath
    cout << "hasPath" << endl;
    while (true)
    {
        int e1, e2;
        cin >> e1 >> e2;
        cout << hasPath(edges, n, e1, e2) << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete edges[i];
    }
    delete edges;
}