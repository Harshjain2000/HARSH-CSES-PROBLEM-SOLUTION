#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,m,x,mod=1e9+7;
	cin>>n>>m;
	
	vector<vector<long long > > dp(n, vector<long long> (m+1));
	
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		if(x==0)
		{
			if(i==0)
			{
				for(long long j=1;j<=m;j++)
				{
					dp[i][j] = 1;
				}
			}
			else{
				for(long long j=1;j<=m;j++)
				{
					if(j==m)
					dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
					else
					dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1] + dp[i-1][j])%mod;
				}
			}
		}
		else{
			if(i==0)
			{
				dp[i][x] = 1;
			}
			else if(x==m)
			dp[i][x] = (dp[i-1][x-1] + dp[i-1][x])%mod;
			else
			dp[i][x] = (dp[i-1][x-1] + dp[i-1][x] + dp[i-1][x+1])%mod;
		}
	}
	
	long long ans=0;
	for(long long i=0;i<=m;i++)
	{
		ans = (ans + dp[n-1][i])%mod;
	}
	cout<<ans;
	return 0;
}
