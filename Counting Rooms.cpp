#include<bits/stdc++.h>
using namespace std;


vector<vector<bool> > vis;

void input(int n, vector<string> &v)
{
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
}

void calldfs(int i, int j, vector<string>&mp)
{
	if(i<0 || j<0 || i>=mp.size() || j>=mp[0].size() || mp[i][j]=='#' || vis[i][j])
	{
		return ;
	}
	vis[i][j] = true;
	calldfs(i+1,j,mp);
	calldfs(i,j+1,mp);
	calldfs(i-1,j,mp);
	calldfs(i,j-1,mp);
}

int solve(int n, int m, vector<string>&mp)
{
	vis.clear();
	vis.resize(n, vector<bool>(m));
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!vis[i][j] && mp[i][j]=='.')
			{
				ans++;
				calldfs(i,j, mp);
			}
		}
	}
	
	return ans;
}

int main()
{
	int n, m;
	cin>>n>>m;
	
	vector<string>mp(n);
	
	input(n, mp);
	cout<<solve(n, m, mp);
	
	return 0;
}
