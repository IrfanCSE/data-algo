#include <bits/stdc++.h>
using namespace std;

int edge, vertices, weight, u, v, i, result = 0;
int adj[100][100];
bool visited[100];

// node class
class Node
{
public:
    int v, cost;
    Node() {}
    Node(int vv, int cc)
    {
        v = vv;
        cost = cc;
    }
};

// priority queue helper
bool operator<(Node a, Node b)
{
    return a.cost > b.cost;
}

// prims algorithm function
void Prims()
{
    // priority queue for sorting cost
    priority_queue<Node> pq;

    // starting node 0 which cost should 0
    pq.push(Node(0, 0));

    // loop until empty queue
    while (!pq.empty())
    {
        Node temp = pq.top();
        pq.pop();
        if (visited[temp.v])
            continue;
        result += temp.cost;
        visited[temp.v] = 1;
        for (i = 0; i < vertices; i++)
        {
            if (visited[i])
                continue;

            // track linked unvisited node which have cost>0
            if (adj[temp.v][i] != 0)
                pq.push(Node(i, adj[temp.v][i]));
        }
    }
    cout << "The cost of mst is : " << result << endl;
}
int main()
{
    cin >> edge >> vertices;
    for (i = 0; i < vertices; i++)
    {
        cin >> u >> v >> weight;
        adj[u][v] = weight;
        adj[v][u] = weight;
    }
    Prims();
    return 0;
}