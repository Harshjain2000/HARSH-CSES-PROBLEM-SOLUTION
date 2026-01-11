#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,x,ans=1;
	cin>>n;
	
	vector<long long>v(n+1);
	
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		v[x] = i;
	}
	
	for(long long i=1;i<n;i++)
	{
		if(v[i+1]<v[i])
		{
			ans++;
		}
	}
	
	cout<<ans;
	
	return 0;
}
