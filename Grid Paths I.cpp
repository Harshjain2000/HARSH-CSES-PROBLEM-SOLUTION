#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,mod=1e9+7;
	cin>>n;
	vector<string>v(n);
	vector<vector<long long > >dp(n, vector<long long> (n));
	
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];
	}
	
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<n;j++)
		{
			if(i==0 && j==0)
			{
				if(v[i][j]!='*')
				dp[0][0] = 1;
				continue;
			}
			if(v[i][j]=='*')
			{
				dp[i][j]=0;
				continue;
			}
			if(i>0 && v[i-1][j]!='*')
			{
				dp[i][j] = (dp[i-1][j] + dp[i][j])%mod;
			}
			if(j>0 && v[i][j-1]!='*')
			{
				dp[i][j] = (dp[i][j-1] + dp[i][j])%mod;
			}
		}
	}
	
	cout<<dp[n-1][n-1];
	
	return 0;
}
