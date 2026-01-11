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
	
	long long tmp=0,ans=0;
	
	for(long long i=0;i<n;i++)
	{
		if(tmp<0)
		{
			tmp=0;
		}
		tmp += v[i];
		
		ans= max(ans, tmp);
	}
	
	if(ans==0)
	{
		long long val = INT_MIN;
		for(long long i=0;i<n;i++)
		{
			val = max(val, v[i]);
		}
		if(val<0)
		{
			cout<<val;
		}
		else{
			cout<<ans;
		}
	}
	else{
		cout<<ans;
	}
	
}
