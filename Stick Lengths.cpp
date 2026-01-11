#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	vector<long long >v(n);
	
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];
	}
	
	sort(v.begin(), v.end());
	long long ans=0, valer=v[0];
	for(long long i=0;i<n;i++)
	{
		ans += abs(valer-v[i]);
	}
	
	for(long long i=1;i<n;i++)
	{
		long long subans = (i+1 - (n-i+1))*(v[i]-v[i-1]);
		
		if(subans<=0)
		{
			ans = ans + subans;
		}
		else{
			break;
		}
	}
	
	cout<<ans;
}
