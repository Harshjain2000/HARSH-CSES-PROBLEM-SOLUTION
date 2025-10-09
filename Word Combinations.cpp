#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s,x;
	cin>>s;
	
	long long n,mod = 1e9+7;
	cin>>n;
	
	map<string,bool> m;
	
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		m[x] = true;
	}
	
	
	vector<long long> dp(n+1);
	dp[0] = 1;
	for(long long i=0;i<s.size();i++)
	{
		for(long long j=i;j>=0;j--)
		{
			string tmp = s.substr(j,i-j+1);
			m[tmp] += 0; 
			if(m[tmp])
			dp[i+1] = (dp[i+1] + dp[j])%mod;
		}
	}
	
	cout<<dp[n];
	return 0;
}
