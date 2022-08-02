#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> bfsOfGraph(int no_of_nodes,vector<ll> adj[])
{
	vector<ll> bfs;
	vector<ll> vis(no_of_nodes+1,0);
	for(ll i = 1;i<=no_of_nodes;i++)
	{
		if(!vis[i]){
			queue<ll> q;
			q.push(i);
			vis[i] = 1;
			while(!q.empty()){
				ll nodes = q.front();
				q.pop();
				bfs.push_back(nodes);
				for(auto it : adj[nodes]){
					if(!vis[it]){
						q.push(it);
						vis[it] = 1;
					}
				}
			}
		}
	}
	return bfs; 
}
int main()
{
	ll nodes,edges;
	cin>>nodes>>edges;
	vector<ll> adjacency[nodes+1]; 
	for(int i =0;i<edges;i++){
		ll node_1,node_2;
		cin>>node_1>>node_2;
		adjacency[node_1].push_back(node_2); 
		adjacency[node_2].push_back(node_1);
	}
	vector<ll> ans = bfsOfGraph(nodes,adjacency);
	for(ll i = 0;i<ans.size();i++)
	 	cout<<ans[i]<<" ";
	 	
	return 0;
}