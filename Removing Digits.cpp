#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	vector<long long> dp(n+1,INT_MAX);
	dp[n] = 0;
	for(long long i=n;i>=0;i--)
	{
		long long val = i;
		
		while(val)
		{
			dp[(i-(val%10))] = min(dp[(i-(val%10))], dp[i] + 1);
			val /= 10;
		}
	}
	
	cout<<dp[0];
	return 0;
}
