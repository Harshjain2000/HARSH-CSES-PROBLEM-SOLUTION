#include<bits/stdc++.h>
using namespace std;


long long solve(long long &n)
{
	long long ans=1,base=2, mod=1e9+7;
	
	while(n)
	{
		if(n%2)
		{
			ans = (ans*base)%mod;
			n--;
		}
		else{
			base = (base*base)%mod;
			n /= 2;
		}
	}
	
	return ans;
}

int main()
{
	long long n;
	cin>>n;
	
	
	cout<<solve(n);
	return 0;
}
