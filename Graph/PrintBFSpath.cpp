#include <iostream>
#include <queue>
#include <map>
using namespace std;

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

map<int, int> getBFSpath_helper(int **edges, int n, int start, int end, bool *visited)
{
    queue<int> pendingVertices;
    map<int, int> map1;
    pendingVertices.push(start);
    visited[start] = true;
    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        // cout << currentVertex << endl;
        for (int i = 0; i < n; i++)
        {
            if (i == currentVertex)
                continue;
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                map1[i] = currentVertex;
                visited[i] = true;
                if (i == end)
                {
                    break;
                }
            }
        }
    }
    return map1;
}

vector<int> getBFSpath(int **edges, int n, int start, int end)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    map<int, int> map1 = getBFSpath_helper(edges, n, start, end, visited);
    vector<int> res;
    res.push_back(end);
    int key = end;
    while (true)
    {
        int temp = map1[key];
        if (temp == start)
        {
            res.push_back(start);
            break;
        }
        else
        {
            res.push_back(temp);
            key = temp;
        }
    }
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

    //BFS
    cout << "BFS" << endl;
    BFS(edges, n);

    //PATH
    cout << "PATH" << endl;
    while (true)
    {
        int start, end;
        cin >> start >> end;
        vector<int> path = getBFSpath(edges, n, start, end);
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