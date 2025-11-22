#include<bits/stdc++.h>
using namespace std;

void print(long long &n,vector<long long>&v)
{
	for(long long i=1;i<=n;i++)
	{
		cout<<v[i]<<" ";
	}
}

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

vector<bool>vis;
vector<long long>dp,ans;

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
		
		maxer = max(maxer , tmp);
	}
	
	dp[idx] = maxer+1;
	return maxer+1;
}

void helper1(long long idx, vector<vector<long long> >&tree,long long extra)
{
	vis[idx] =  true;
	ans[idx] = max(dp[idx] -1, extra);
	
	long long a=0,b=0;
	for(long long j=0;j<tree[idx].size();j++)
	{
		if(vis[tree[idx][j]])
		{
			continue;
		}
		if(a==0)
		{
			a = dp[tree[idx][j]];
		}
		else if(b==0)
		{
			if(a>dp[tree[idx][j]])
			{
				b = dp[tree[idx][j]];
			}
			else{
				b= a;
				a = dp[tree[idx][j]];
			}
		}
		else if(a<=dp[tree[idx][j]])
		{
			b = a;
			a = dp[tree[idx][j]];
		}
		else{
			b = max(b,dp[tree[idx][j]]);
		}
	}
//	cout<<a<<" "<<b<<" "<<extra<<" "<<ans[idx]<<endl;
	if(extra>a)
	{
		b = a;
		a = extra;
	}
	else{
		b = max(extra,b);
	}
	for(long long j=0;j<tree[idx].size();j++)
	{
		if(vis[tree[idx][j]])
		{
			continue;
		}
		long long val=0;
		if(a!=dp[tree[idx][j]])
		{
			val = a;
		}
		else{
			val = b;
		}
		helper1(tree[idx][j], tree,val+1);
	}
	
	return ;
}


void solve(long long n, vector<vector<long long> >&tree)
{
	vis.clear();dp.clear();ans.clear();
	dp.resize(n+1,0);
	ans.resize(n+1,0);
	vis.resize(n+1,false);
	helper(1, tree);
	vis.clear();
	vis.resize(n+1,false);
	helper1(1, tree,0);
}




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long n;
	vector<vector<long long > >tree;
	input(n,tree);

	solve(n,tree);
	print(n,ans);	
	return 0;
}
