#include<bits/stdc++.h>
using namespace std;

#define mod (long long)(1e9+7)

int main()
{
	long long n,ct=0,ans=0,a,b;
	cin>>n;
	vector<pair<long long,long long> >v;
	for(long long i=0;i<n;i++)
	{
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	
	sort(v.begin(), v.end());
	for(long long i=0;i<n;i++)
	{
		ct += v[i].first;
		ans += (v[i].second-ct);
	}
	cout<<ans;
	
	return 0;
}
