#include<bits/stdc++.h>
using namespace std;

void input(long long &n, vector<vector<long long> >&tree)
{
	long long a,b;
	cin>>n;
	tree.clear();
	tree.resize(n+1);
	for(long long i=1;i<n;i++)
	{
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}	
}

long long ans = 0;
vector<bool>vis;

long long helper(long long idx, vector<vector<long long> >&tree)
{
	vis[idx] =  true;
	
	long long maxer =0;
	for(long long j=0;j<tree[idx].size();j++)
	{
		if(vis[tree[idx][j]])
		{
			continue;
		}
		long long tmp = helper(tree[idx][j], tree);
		
		ans  = max(ans, tmp + 1 + maxer);
		maxer = max(maxer , tmp);
	}
	
	vis[idx] = false;
	ans = max(maxer+1, ans);
	return maxer+1;
}


long long solve(long long n, vector<vector<long long> >&tree)
{
	vis.clear();
	vis.resize(n+1,false);
	ans = 0;
	

	helper(1,tree);
	
	return ans-1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long n;
	vector<vector<long long > >tree;
	input(n,tree);
	cout<<solve(n,tree);
		
	return 0;
}
