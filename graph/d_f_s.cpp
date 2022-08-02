#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void dfs(ll node,vector<ll>&vis,vector<ll> adj[],vector<ll> &store){
	store.push_back(node);
	vis[node] = 1;
	for(auto it : adj[node]){
		if(!vis[it])
			dfs(it,vis,adj,store);
	}
}
vector<ll> dfsOfGraph(ll nodes,vector<ll>adj[]){
	vector<ll> store;
	vector<ll> vis(nodes+1,0);
	for(ll i = 1;i<=nodes;i++){
		if(!vis[i])
			dfs(i,vis,adj,store);
	}
	return store;
}
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
	cout<<"\n"<<"dfs of graph is :"<<"\n";
	vector<ll> ans = dfsOfGraph(nodes,adjacency);
	for(ll i : ans)
	cout<<i<<" ";
	return 0;
}