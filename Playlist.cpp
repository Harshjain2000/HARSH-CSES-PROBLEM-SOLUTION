#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,x;
	cin>>n;
	
	map<long long,long long>m;
	long long ans=0,idx = -1;
	
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		if(m.find(x)!=m.end())
		{
			idx = max(idx,m[x]);
		}
		ans = max(ans, i-idx);
		m[x] = i;
	}
	
	cout<<ans;
}
