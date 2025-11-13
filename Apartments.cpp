#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,m,k,count=0,x,j=0;
	cin>>n>>m>>k;
	
	vector<long long >a(n),b(m);
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(long long i=0;i<m;i++)
	{
		cin>>b[i];
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	for(long long i=0;i<m;i++)
	{
		if(j<n)
		{
			if((a[j]-k)<=b[i] && (a[j]+k)>=b[i])
			{
				count++;
				j++;
			}
			else if((a[j]+k)<b[i])
			{
				i--;
				j++;
			}
		}
	}
	cout<<count;
	return 0;
}
