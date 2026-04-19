#include<bits/stdc++.h>
using namespace std;

#define mod (long long)(1e9+7)

int main()
{
	long long n,t;
	cin>>n>>t;
	vector<long long>v(n);
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];
	}
	
	long long l=0,r=t*v[0];
	
	while(l<=r)
	{
		long long mid = l+((r-l)>>1),count=0;
		
		for(long long i=0;i<n;i++)
		{
			if(count >= (t-mid/v[i]))
			{
				count = t;
				break;
			}
			count += mid/v[i];
			
		}
		
		if(count>=t)
		{
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	
	cout<<l;
	
	return 0;
}
