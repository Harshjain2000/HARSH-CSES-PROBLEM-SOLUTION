#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n, ans = 0;
	cin>>n;
	
	vector<long long>v(n), dp(35,0);
	
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];
		
		for(long long j=34;j>=0;j--)
		{
			if(!(v[i] & (1ll<<j)))
			{
				continue;
			}
			
			if(!dp[j])
			{
				dp[j] = v[i];
				ans++;	
				break; 
			}
			
			v[i] = (v[i] ^ dp[j]);
		}
	}
	
	cout<<(1ll<<ans);
		
	return 0;
}
