#include<bits/stdc++.h>
using namespace std;

#define mod (long long)(1e9+7)

int main()
{
	long long n,x, ans=1;
	cin>>n;
	map<long long ,long long>m;
	
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		m[x]++;
		
	}
	
	for(auto it:m)
	{
		ans = ((ans%mod)*((it.second+1)%mod))% mod;
	}
	ans = (ans-1+mod) % mod;
	cout<<ans;
	
	return 0;
}
