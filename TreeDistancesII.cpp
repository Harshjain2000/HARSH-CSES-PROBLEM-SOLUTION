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
vector<pair<long long ,long long> >dp;
vector<long long>ans;

pair<long long,long long> helper(long long idx, vector<vector<long long> >&tree)
{
	vis[idx] =  true;
	
	long long maxer =0,nnode = 0;
	for(long long j=0;j<tree[idx].size();j++)
	{
		if(vis[tree[idx][j]])
		{
			continue;
		}
		pair<long long,long long> tmp = helper(tree[idx][j], tree);
		maxer += tmp.first;
		nnode += tmp.second;
	}
	
	dp[idx] = make_pair(maxer+nnode, nnode+1);
	return dp[idx];
}

void helper1(long long idx, vector<vector<long long> >&tree,long long pred, long long &n)
{
	vis[idx] =  true;
	ans[idx] = pred;
	long long tmpn=0;
	for(long long j=0;j<tree[idx].size();j++)
	{
		if(vis[tree[idx][j]])
		{
			continue;
		}
		helper1(tree[idx][j], tree, pred - 2*dp[tree[idx][j]].second + n,n);
	}
	return ;
}


void solve(long long n, vector<vector<long long> >&tree)
{
	vis.clear();dp.clear();ans.clear();
	dp.resize(n+1);
	ans.resize(n+1,0);
	vis.resize(n+1,false);
	pair<long long ,long long> intial = helper(1, tree);
	ans[1] = intial.first;
	vis.clear();
	vis.resize(n+1,false);
	helper1(1, tree, intial.first,n);
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
