#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,x,mod = 1e9+7;
	cin>>n>>x;
	
	
	vector<vector<long long > > dp(2,vector<long long> (x+1,0));
	vector<long long> coin(n);
	
	for(long long i=0;i<n;i++)
	{
		cin>>coin[i];
	}
	
	for(long long i=0;i<=n;i++)
	{
		for(long long j=0;j<=x;j++)
		{
			if(j==0)
			{
				dp[i%2][j] = 1;
			}
			else if(i==0)
			{
				dp[i%2][j] = 0;
			}
			else if((j-coin[i-1])>=0)
			{
				dp[i%2][j] = (dp[(i-1)%2][j] + dp[i%2][j-coin[i-1]])%mod;
			}
			else {
				dp[i%2][j] = dp[(i-1)%2][j];
			}
		//	cout<<dp[i%2][j]<<" ";
		}
	//	cout<<endl;
	}
	
	cout<<dp[(n%2)][x];
	return 0;
}
