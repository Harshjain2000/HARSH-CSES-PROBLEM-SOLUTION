#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
	long long n,k,ans=0,sum=0,x,a,b,c;
	cin>>n>>k>>x>>a>>b>>c;
	
	for(long long i=0;i<n;i++)
	{
		if(min(min(i+1,n-i), k)%2)
		ans = ans^x;
		x = (((a*x)%c) + b)%c;
	}
	
	cout<<ans;
}
