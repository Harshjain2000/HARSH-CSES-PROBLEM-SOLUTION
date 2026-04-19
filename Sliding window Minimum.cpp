#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long n,k,ans=0,sum=0,x,a,b,c;
	cin>>n>>k>>x>>a>>b>>c;
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> > , greater<pair<long long,long long> > >window;
	
	for(long long i=0;i<n;i++)
	{
		window.push(make_pair(x,i));
		x = (((a*x)%c) + b)%c;
		
		while(!window.empty() && window.top().second<(i-k+1))
		{
			window.pop();
		}
		if(window.size()>=k)
		ans = ans^(window.top().first);
	}
	
	cout<<ans;
	return 0;
}
