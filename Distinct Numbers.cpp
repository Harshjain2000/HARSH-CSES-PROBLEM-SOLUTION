#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,x,count=0;
	cin>>n;
	
	map<long long ,long long>m;
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		m[x]++;
		if(m[x]==1)
		{
			count++;
		}
	}
	cout<<count;
	return 0;
}
