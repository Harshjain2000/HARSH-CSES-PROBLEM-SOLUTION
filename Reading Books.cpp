#include<bits/stdc++.h>
using namespace std;

#define mod (long long)(1e9+7)

int main()
{
	long long n,val1=0;
	cin>>n;
	vector<long long> v(n);
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];
	}
	
	sort(v.begin(), v.end());
	for(long long i=0;i<(n-1);i++)
	{
		val1 += v[i];
	}
	if(val1 > v[n-1])
	{
		cout<<val1+v[n-1];
	}
	else
		cout<<2*v[n-1];
	
	return 0;
}
