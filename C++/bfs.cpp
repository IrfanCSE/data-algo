#include <bits/stdc++.h>
using namespace std;

int visited[100000];
int level[100000];
vector<int> vec[100000];

void bfs(int s)
{
  visited[s] = 1;
  level[s] = 0;
  queue<int> q;
  q.push(s);

  while (!q.empty())
  {
    int x = q.front();
    cout<<x<<" ";
    q.pop();
    for (int i = 0; i < vec[x].size(); i++)
    {
      int y = vec[x][i];
      if (visited[y] == 0)
      {
        visited[y] = 1;
        level[y] = level[x] + 1;
        q.push(y);
      }
    }
  }
}
int main()
{
  int i, ver, edg, u, v, z = 0, s;
  cout << "Input vertex and edge" << endl;
  cin >> ver >> edg;
  cout << "input relation between node" << endl;
  for (i = 0; i < edg; i++)
  {
    cin >> u >> v;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }
  cout << "inupt starting node" << endl;
  cin >> s;
  bfs(s);

  return 0;
}
