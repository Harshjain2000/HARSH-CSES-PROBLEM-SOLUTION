#include<bits/stdc++.h>
using namespace std;

void input(vector<long long>&v, long long len)
{
	for(long long i=0;i<len;i++)
	{
		cin>>v[i];
	}
}

void solve(vector<vector<long long > >&dp, vector<long long>&a,long long a_len, vector<long long >&b, long long b_len, vector<long long> &ans)
{
	for(long long i=0;i<=a_len;i++)
	{
		for(long long j=0;j<=b_len;j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j]=0;
			}
			else{
				long long x = (a[i-1] == b[j-1]);
				
				dp[i][j] = max(dp[i-1][j-1] + x,max(dp[i-1][j] , dp[i][j-1]));
			}
		}
	}
	
	long long i=a_len,j=b_len;
	
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
			ans.push_back(a[i-1]);
			i--;j--;
		}
		else{
			if(dp[i-1][j]>dp[i][j-1])
			{
				i--;
			}
			else{
				j--;
			}
		}
	}
	reverse(ans.begin(), ans.end());
	
}

int main()
{
	long long n,m;
	cin>>n>>m;
	
	vector<long long> ans;
	
	vector<long long>a(n),b(m);
	
	vector<vector<long long  > >dp(n+1, vector<long long >(m+1));
	
	input(a,n);
	input(b,m);
	
	solve(dp,a,n,b,m,ans);
	
	cout<<dp[n][m]<<"\n";
	for(long long i=0;i<ans.size();i++)
	cout<<ans[i]<<" ";
	return 0;
}
