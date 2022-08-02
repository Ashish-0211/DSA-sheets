#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll nodes,edges;
	cin>>nodes>>edges;
	vector<ll> adjacency[nodes+1]; // if weighted than use vector<apir<int,int>> adj[nodes+1];
	for(int i =0;i<edges;i++){
		ll node_1,node_2; // ll weight;
		cin>>node_1>>node_2; // cin>>weight;
		adjacency[node_1].push_back(node_2); // adj[node_1].push_back({node_2,weight});
		adjacency[node_2].push_back(node_1);// adj[node_2].push_back({node_1,weight});
	}
	for(int i = 0;i<nodes;i++){
	   for(int j = 0;j<nodes;j++)
			cout<<adjacency[i][j]<<" ";
	cout<<"\n";
	}
	return 0;
}