#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,x,idx = 0, ans=0;
	cin>>n;
	
	map<long long ,long long>m;
	
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		
		if(m.find(x)!=m.end() && m[x]>=idx)
		{
			long long l = i-idx, r = i-m[x]-1;
			ans += (l*(l+1))/2ll - (r*(r+1))/2ll;
			idx = m[x]+1;
		}
		m[x] = i;
	}
	
	ans += ((n-idx)*(n-idx+1))/2ll;
	
	cout<<ans;
	
	return 0;
}
