#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long n,k,ans=0,sum=0,x,a,b,c;
	cin>>n>>k>>x>>a>>b>>c;
	queue<long long>window;
	
	for(long long i=0;i<n;i++)
	{
		sum += x;
		window.push(x);
		x = (((a*x)%c) + b)%c;
		if(window.size()==k)
		{
			ans = ans^sum;
			sum -= window.front();
			window.pop();
		}
	}
	
	cout<<ans;
	return 0;
}
