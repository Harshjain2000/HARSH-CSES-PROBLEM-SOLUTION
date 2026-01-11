#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,low=0;
	cin>>n;
	vector<long long >v(n);
	
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	for(long long i=0;i<n;i++)
	{
		if((low+1)<v[i])
		{
			break;
		}
		else{
			low += v[i];
		}
	}
	
	cout<<low+1;
}
