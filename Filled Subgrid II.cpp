#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,k;
	cin>>n>>k;
	
	vector<long long>ans(26);
	vector<string>v(n);
	
	vector<vector<long long> >dp(n,vector<long long> (n));
	vector<vector<long long> >matrix(n,vector<long long> (n));
	
	
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];
	}
	
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<n;j++)
		{
			if(i==0)
			{
				dp[i][j] = 1;
			}
			else{
				if(v[i][j]==v[i-1][j])
				{
					dp[i][j] = dp[i-1][j]+1;
				}
				else{
					dp[i][j] = 1;
				}
			}
			
			long long counter = INT_MAX,subans=0;
			for(long long l = j;l >=0 ;l-- )
			{
				if(v[i][l]!=v[i][j])
				{
					break;
				}
				else if(counter!=INT_MAX && dp[i][l] <= counter)
				{
					subans += matrix[i][l];
					break;
				}
				counter= min(counter , dp[i][l]);
				subans += counter;
			}
			matrix[i][j] = subans;
			ans[v[i][j]-'A'] += subans;
		}
	}
	
	for(long long i=0;i<26;i++)
	{
		if(ans[i]!=0)
		cout<<ans[i]<<endl;
	}
	return 0;
}
