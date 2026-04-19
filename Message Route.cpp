#include<bits/stdc++.h>
using namespace std;

vector<long long>ast,vis,ans;




void result()
{
	if(ans.size()==0)
	{
		cout<<"IMPOSSIBLE";
		return ;
	}
	cout<<ans.size()<<endl;
	
	for(long long i=ans.size()-1;i>=0;i--)
	{
		cout<<ans[i]<<" ";
	}
}
int main()
{
	long long n,m,a,b;
	cin>>n>>m;
	
	ast.clear();
	ans.clear();
	vis.clear();
	ast.resize(n+1);
	vis.resize(n+1);
	map<long long ,vector<long long> >graph;
	
	for(long long i=0;i<m ;i++)
	{
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	
	a = 1;
	queue<long long >q;q.push(1);vis[1]= true;
	
	while(!q.empty())
	{
		for(long long i=0;i<graph[q.front()].size();i++)
		{
			if(!vis[graph[q.front()][i]])
			{
				vis[graph[q.front()][i]] = true;
			
				q.push(graph[q.front()][i]);
				ast[graph[q.front()][i]] = q.front();
			}
		}
		q.pop();
	}
	
	a = n;
	if(ast[n]!=0){
		ans.push_back(n);
		while(a!=1)
		{
			a = ast[a];
			ans.push_back(a);
		}
	}
	result();
	
	return 0;
}
