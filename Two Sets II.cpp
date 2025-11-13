#include<bits/stdc++.h>
using namespace std;

long long powerful(long long base, long long val,long long mod)
{
	long long ans = 1;
	
	while(val)
	{
		if(val%2)
		{
			val--;
			ans = (ans*base)%mod;
		}
		else{
			val /= 2;
			base = (base*base)%mod;
		}
	}
	
	return ans;
}

long long solve(long long &n, long long mod)
{
	long long sum = (n*(n+1))/2;
	if(sum%2) 
	{
		return 0;
	}
	map<long long,long long> m;
	
	m[0] = 1;
	for(long long i=1;i<=n;i++)
	{
		for(auto it=m.rbegin();it!=m.rend();it++)
		{
			m[it->first + i] = (m[it->first+1] + 1)%mod; 
		}
	}
	
	return ((((m[sum/2]*(m[sum/2]-1)))%mod) * powerful(2,mod-2,mod))%mod;
}

int main()
{
	long long n;
	cin>>n;
	cout<<solve(n,1e9+7);	
	return 0;
}
