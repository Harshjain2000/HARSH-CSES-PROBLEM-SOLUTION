#include<bits/stdc++.h>
using namespace std;

long long val2;

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
	vector<long long> m(sum/2+1);
	
	m[0] = 1;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=min(sum/2, i*(i+1)/2);j>=i;j--)
		{
			m[j] = (m[j] + m[j-i])%mod; 
		}
	} 
//	cout<<m[sum/2]<<"\n";
	return (m[sum/2]*val2)%mod;
}

int main()
{
	long long n;
	cin>>n;
	long long mod = 1e9+7;
	val2 =  powerful(2,mod-2ll,mod);
	cout<<solve(n,1e9+7);	
	return 0;
}
