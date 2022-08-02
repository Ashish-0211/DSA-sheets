#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool checkCycle(ll nodes,ll parent,vector<ll> &vis,vector<ll> adj[]){
	vis[nodes] = 1;
	for(auto it : adj[nodes]){
		if(!vis[it]){
			if(checkCycle(it,nodes,vis,adj))
				return true;
		}
		else if(it != parent)
			return true;		
	}
	return false;
}
bool isCycle(ll nodes,vector<ll> adj[]){
	vector<ll> vis(nodes+1,0);
	for(ll i = 1;i<=nodes;i++){
		if(!vis[i])
			if(checkCycle(i,-1,vis,adj))
				return true;
	}
	return false;
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
	if(isCycle(nodes,adjacency))
	cout<<"cycle is present"<<"\n";
	else if(! isCycle(nodes,adjacency))
	cout<<"Cycle is not present"<<"\n";
	return 0;
}