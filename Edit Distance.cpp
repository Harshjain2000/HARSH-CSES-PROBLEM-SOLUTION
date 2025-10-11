#include<bits/stdc++.h>
using namespace std;

int main()
{
	string sn,sm;
	cin>>sn>>sm;
	
	long long n = sn.size();
	long long m = sm.size();
	
	
	vector<vector<long long> >dp(n+1, vector<long long> (m+1));
	for(long long i=0;i<=n;i++)
	{
		for(long long j=0;j<=m;j++)
		{
			if(i==0 && j==0)
			{
				dp[i][j] = 0;
			}
			else if(i==0)
			{
				dp[i][j] = j;
			}
			else if(j==0)
			{
				dp[i][j] = i;
			}
			else{
				long long x = (sn[i-1]!=sm[j-1]);
				dp[i][j] = min(dp[i-1][j-1] + x, min(dp[i-1][j]+1, dp[i][j-1]+1));
			}
		//	cout<<dp[i][j]<<" ";
		}
	//	cout<<"\n";
	}
	
	cout<<dp[n][m];
	return 0;
}
