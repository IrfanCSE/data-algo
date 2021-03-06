// BFS algorithm in C++

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int vertices)
    {
        numVertices = vertices;
        adjLists = new list<int>[vertices];
    }

    void addEdge(int src, int dest)
    {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }

    void BFS(int startVertex)
    {
        visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++)
            visited[i] = false;

        list<int> queue;

        visited[startVertex] = true;
        queue.push_back(startVertex);

        list<int>::iterator i;

        while (!queue.empty())
        {
            int currVertex = queue.front();
            cout << "Visited " << currVertex << " ";
            queue.pop_front();

            for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
            {
                int adjVertex = *i;
                if (!visited[adjVertex])
                {
                    visited[adjVertex] = true;
                    queue.push_back(adjVertex);
                }
            }
        }
    }
};

int main()
{
    int Vertex, edge, item;

    cout << "Insert Amount of vertex and edge." << endl;
    cin >> Vertex >> edge;
    Graph graph(Vertex);
    cout << "Insert relation between node." << endl;
    for (int i = 0; i < edge; i++)
    {
        int u,v;
        cin>>u>>v;
        graph.addEdge(u,v);
    }

    cout << "Start node is : ";
    cin>>item;
    graph.BFS(item);

    return 0;
}