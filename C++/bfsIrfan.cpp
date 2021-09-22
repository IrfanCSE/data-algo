#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge, index = 0;
    cout << "Insert Amount of node and edge." << endl;
    cin >> node >> edge;
    char startNode;
    char graph[edge][2];
    char output[node];

    cout << "Insert relation between node." << endl;

    for (int i = 0; i < edge; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Start node is : ";
    cin >> startNode;
    output[0] = startNode;
    int count = 0;
    bool isExist = false;
    char selected;

    // insert output.
    while (count < node)
    {

        // checking graph.
        for (int i = 0; i < edge; i++)
        {
            selected = output[index];
            // 1st index of row.
            if (graph[i][0] == selected)
            {
                // is available in output Array.
                for (int j = 0; j < node + 1; j++)
                {
                    if (output[j] == graph[i][1])
                    {
                        isExist = true;
                        break;
                    }
                }
                if (!isExist)
                {
                    output[++count] = graph[i][1];
                    isExist = false;
                }
            }

            // 2nd index of row.
            else if (graph[i][1] == selected)
            {
                // is available in output Array.
                for (int j = 0; j < node + 1; j++)
                {
                    if (output[j] == graph[i][0])
                    {
                        isExist = true;
                        break;
                    }
                }
                if (!isExist)
                {
                    output[++count] = graph[i][0];
                    isExist = false;
                }
            }
        }
        index++;
    }

    for (int i = 0; i < node; i++)
    {
        cout << output[i] << " ";
    }
}