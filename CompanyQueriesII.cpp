#include<bits/stdc++.h>
using namespace std;

void input(long long &n,long long &q, vector<vector<long long> >&tree)
{
	long long a;
	cin>>n>>q;
	tree.clear();
	tree.resize(n+1);
	for(long long i=2;i<=n;i++)
	{
		cin>>a;
		tree[a].push_back(i);
	}	
}

long long ans = 0;
vector<bool>vis;
vector<long long >stk;
vector<vector<long long> >pre;

void helper(long long idx, vector<vector<long long> >&tree)
{
	vis[idx] =  true;
	pre[idx].push_back(stk.size()-1);
	
	
	for(long long j=1;j<=stk.size();j*=2)
	{
		pre[idx].push_back(stk[stk.size()-j]);
	}
	
	stk.push_back(idx);
	
	for(long long j=0;j<tree[idx].size();j++)
	{
		if(vis[tree[idx][j]])
		{
			continue;
		}
		helper(tree[idx][j], tree);
		
	}
	stk.pop_back();
}

long long getequalhp(long long &a, long long b)
{
	while(1)
	{
		if(b==0)
		{
			return a;
		}
		if(b==1)
		{
			return pre[a][1];
		}
		long long tmp = log2(b);
		a = pre[a][tmp+1];
		b -= pow(2,tmp);
	}
	
	return -1;
}

long long query()
{
	long long a,b;
	cin>>a>>b;
	
	if(pre[a][0]>pre[b][0])
	{
		a = getequalhp(a, pre[a][0]-pre[b][0]);
	}
	else if(pre[a][0]<pre[b][0])
	{
		b = getequalhp(b, pre[b][0]-pre[a][0]);
	}
	
	while(1)
	{
		if(a==b)
		{
			return a;
		}
		long long j=1;
		for( j=1;j<pre[a].size();j++)
		{
			if(pre[a][j]==pre[b][j])
			{
				break;
			}
		}
		if(j==1)
		{
			return pre[a][1];
		}
		a = pre[a][j-1];
		b = pre[b][j-1];
	}
	
	return -1;
}


void solve(long long n, vector<vector<long long> >&tree)
{
	vis.clear();
	pre.clear();
	pre.resize(n+1);
	stk.clear();
	stk.push_back(-1);
	vis.resize(n+1,false);	
	helper(1,tree);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long n,q;
	vector<vector<long long > >tree;
	input(n,q,tree);
	solve(n,tree);
	
	for(long long i=0;i<q;i++)
		cout<<query()<<endl;
	return 0;
}
