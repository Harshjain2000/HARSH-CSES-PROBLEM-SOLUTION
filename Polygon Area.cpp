#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long n,ans=0,x0,y0,x,y,xp,yp;
	cin>>n;
	
	for(long long i=0;i<n;i++)
	{
		cin>>x>>y;
		if(i==0)
		{
			x0 = x;
			y0 = y;
		}
		else{
			ans += (x*yp-xp*y);
		}
		
		xp = x;yp = y;
	}
	
	ans += (x0*yp-xp*y0);
	cout<<abs(ans);
	return 0;
}
