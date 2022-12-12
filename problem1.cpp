#include <bits/stdc++.h>
using namespace std;
#define N 100
vector<int> g[N];
int dis[N];
int visited[N];
int node, edge;
void bfs(int v)
{
    queue<int> q;
    q.push(v);
    visited[v] = 1;
    dis[v] = 0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int i = 0; i < g[p].size(); i++)
        {
            int next = g[p][i];
            if (visited[next] == 0)
            {
                q.push(next);
                visited[next] = 1;
                dis[next] = dis[p] + 1;
            }
        }
    }
}

void dfs(int v)
{
    stack<int> q;
    q.push(v);
    visited[v] = 1;
    dis[v] = 0;

    while (!q.empty())
    {
        int p = q.top();

        q.pop();

        for (int i = 0; i < g[p].size(); i++)
        {
            int next = g[p][i];
            if (visited[next] == 0)
            {
                q.push(next);
                visited[next] = 1;
                dis[next] = dis[p] + 1;
            }
        }
    }
}

int main()
{
    freopen("graphGenerate.txt", "r", stdin);
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto start1 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    dfs(10);

    auto end1 = chrono::high_resolution_clock::now();
    double time_taken1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
    time_taken1 *= 1e-9;
    cout << "Time taken by DFS is : " << fixed
         << time_taken1 << setprecision(9);
    cout << " sec" << endl;

    auto start2 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    bfs(10);

    auto end2 = chrono::high_resolution_clock::now();
    double time_taken2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
    time_taken2 *= 1e-9;
    cout << "Time taken by BFS is : " << fixed
         << time_taken2 << setprecision(9);
    cout << " sec" << endl;
}