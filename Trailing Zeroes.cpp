#include<bits/stdc++.h>
using namespace std;


long long solve(long long &n)
{
	long long ans=0,base=5;
	
	while(n>=base)
	{
		ans += (n/base);
		base *= 5;
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
