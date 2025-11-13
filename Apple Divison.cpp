#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,sum=0;
	cin>>n;
	
	vector<long long >p(n);
	map<long long ,long long>m;
	m[0] = 1;
	for(long long i=0;i<n;i++)
	{
		cin>>p[i];
		sum += p[i];
		
		for(auto it=m.rbegin();it!=m.rend();it++)
		{
			m[it->first + p[i]] = 1;
		}
	}
	
	long long summer = 0,helper=0;
	for(auto it:m)
	{
		if(it.first<=(sum/2))
		{
			helper = max(helper, it.first);
		}
	}
	
	cout<<(sum - 2*helper);
	return 0;
}
