#include<bits/stdc++.h>
using namespace std;

vector<bool>vis;
long long flag = 0, nodes=-1,nodee=-1;
vector<long long>parent,ans;

void dfs(map<long long , vector<long long > >&graph, long long e)
{
	if(vis[e])
	{
		return ;
	}
	vis[e] = true;
	for(long long i=0;i<graph[e].size();i++)
	{
		if(!vis[graph[e][i]])
		{
			parent[graph[e][i]] = e;
			dfs(graph, graph[e][i]); 
		}
		else if(parent[e]!=graph[e][i]){
			nodes = graph[e][i];
			nodee = e;
			flag = 1;
		}
		
		if(flag)
		{
			return ;
		}
	}
}

void print()
{
	if(nodes==-1)
	{
		cout<<"IMPOSSIBLE";
		return;
	}

	
	ans.push_back(nodes);
	for(long long i=nodee;i!=nodes && i!=parent[i];i=parent[i])
	{
		ans.push_back(i);
	}
	ans.push_back(nodes);
	
	cout<<ans.size()<<"\n";
	
	for(long long i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}

int main()
{
	long long n,m,a,b;
	
	cin>>n>>m;
	
	map<long long ,vector<long long> >graph;
	
	for(long long i=0;i<m;i++)
	{
		cin>>a>>b;
		
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	ans.clear();
	vis.clear();vis.resize(n+1);
	parent.clear();parent.resize(n+1);
	
	for(auto it:graph)
	{
		if(!vis[it.first])
		{
			dfs(graph, it.first);
			if(flag)
			{
				break;
			}
		}
	}
	
	print();
	
}
