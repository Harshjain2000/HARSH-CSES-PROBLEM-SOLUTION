#include<bits/stdc++.h>
using namespace std;

int main()
{

		long long n,x,ans=0,last=-1;
		cin>>n;
		
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			
			ans += max(0ll, last-x);
			last = max(last, x);
		}
		cout<<ans<<"\n";
	
	return 0;
}
