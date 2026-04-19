#include<bits/stdc++.h>
using namespace std;



int main()
{
	long long n,q,a,b;
	cin>>n>>q;
	
	vector<long long>v(n+1);
	
	
	for(long long i=0;i<n;i++)
	{
		cin>>v[i+1];
		v[i+1] += v[i];
	}
	
	for(long long i=0;i<q;i++)
	{
		cin>>a>>b;
		
		cout<<v[b]-v[a-1]<<"\n";
	}
	
	return 0;
}
