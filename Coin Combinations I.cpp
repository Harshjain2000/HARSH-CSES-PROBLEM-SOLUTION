#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,x,mod = 1e9+7;
	cin>>n>>x;
	
	
	vector<long long> dp(x+1), coin(n);
	dp[0] = 1; 
	
	for(long long i=0;i<n;i++)
	{
		cin>>coin[i];
	}
	
	for(long long i=1;i<=x;i++)
	{
		for(long long j=0;j<n;j++)
		{
			if((i-coin[j])>=0)
			{
				dp[i] = (dp[i] + dp[i-coin[j]])%mod;
			}
		}
	}
	
	cout<<dp[x];
	return 0;
}
