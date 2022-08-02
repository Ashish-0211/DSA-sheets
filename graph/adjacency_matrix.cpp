#include <bits/stdc++.h>
using namespace std;
int main()
{
    int no_of_nodes, edges;
    cin >> no_of_nodes >> edges;
    cout << "\n";
    int adj[no_of_nodes + 1][no_of_nodes + 1];
    for(int i = 0;i<no_of_nodes;i++)
    for(int j = 0;j<no_of_nodes;j++)
    adj[i][j] = 0;
    
    for (int i = 0; i < edges; i++)
    {
        int node_1, node_2;
        cin >> node_1 >> node_2;
        adj[node_1][node_2] = 1;
        adj[node_2][node_1] = 1;
    }
    cout << "The graph representation in adjacency matrix"
         << "\n";
    for (int i = 0; i < no_of_nodes; i++)
    {
        for (int j = 0; j < no_of_nodes; j++)
            cout << adj[i][j] << " ";

        cout << "\n";
    }
    return 0;
}