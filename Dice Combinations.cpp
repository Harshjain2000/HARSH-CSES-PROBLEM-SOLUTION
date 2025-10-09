#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,mod = 1e9+7;
	cin>>n;
	
	vector<long long >dp(n+1);
	dp[0] = 1;
	
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=6 && (i-j)>=0;j++)
		{
			dp[i] = (dp[i] + dp[i-j])%mod;
		}
	}
	cout<<dp[n];
	return 0;
}
