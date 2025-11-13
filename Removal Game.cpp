#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,sum=0;
	cin>>n;
	
	vector<long long>v(n),dp(n);
	
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];
		sum += v[i];
	}
	
	for(long long i=n-1;i>=0;i--)
	{
		for(long long j=i;j<n;j++)
		{
			if(i==j)
			{
				dp[j] = v[i];
			}
			else{
				dp[j] = max(v[i]-dp[j], v[j]-dp[j-1]);
			}
		}
	}
	
	cout<<(sum + dp[n-1])/2;
}
