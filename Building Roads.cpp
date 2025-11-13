#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,a,b;
	cin>>n>>m;
	
	vector<int> parent(n+1);
	
	for(int i=0;i<=n;i++)
	{
		parent[i] = i;
	}
	
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		
		int pa = a;
		
		while(pa!=parent[pa])
		{
			pa = parent[pa];
		}
		int pb = b;
		while(pb!=parent[pb])
		{
			pb = parent[pb];
		}
		parent[pb] = pa;
		pb = a;
		while(pb!=pa)
		{
			int pbc = parent[pb];
			parent[pb] = pa;
			pb = pbc;
		}
		pb = b;
		while(pb!=pa)
		{
			int pbc = parent[pb];
			parent[pb] = pa;
			pb = pbc;
		}
	}
	
	vector<int>ans;
	for(int i=1;i<=n;i++)
	{
		if(parent[i] == i)
		{
			ans.push_back(i);
		}
	}
	cout<<ans.size()-1<<"\n";
	
	for(int i=1;i<ans.size();i++)
	{
		cout<<ans[i-1]<<" "<<ans[i]<<"\n";
	}
	
	return 0;
}
