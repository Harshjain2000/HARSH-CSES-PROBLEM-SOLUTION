#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,x;
	cin>>n>>x;
	
	vector<long long > dp(x+1,INT_MAX),coin(n);
	dp[0] = 0;
	
	for(long long i=0;i<n;i++)
	{
		cin>>coin[i];
	}
	
	for(long long i=1;i<=x;i++)
	{
		for(long long j=0;j<n;j++)
		{
			if((i-coin[j])<0)
			{
				continue;
			}
			dp[i] = min(dp[i], dp[i-coin[j]]+1);
		}
	}
	
	if(dp[x]==INT_MAX)
	{
		cout<<-1;
	}
	else
	cout<<dp[x];
	return 0;
}
