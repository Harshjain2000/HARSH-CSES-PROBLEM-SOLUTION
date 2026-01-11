#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,a,b;
	cin>>n;
	vector<pair<long long,long long > >v(n);
	
	for(long long i=0;i<n;i++)
	{
		cin>>a>>b;
		v[i] = make_pair(b,a);
	}
	
	sort(v.begin(), v.end());
	
	long long ans=0, lastwatch=0;
	for(long long i=0;i<n;i++)
	{
		if(lastwatch<=v[i].second)
		{
			lastwatch = v[i].first;
			ans++;
		}
	}
	
	cout<<ans;
}
