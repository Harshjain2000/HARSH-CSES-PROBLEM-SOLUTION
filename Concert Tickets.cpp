#include<bits/stdc++.h>
using namespace std;



int main()
{
	long long n,m,x;
	cin>>n>>m;
	
	multiset<long long>h;
	
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		h.insert(x);
	}
	
	long long count=0;
	for(long long i=0;i<m;i++)
	{
		cin>>x;
		
		auto y = h.upper_bound(x);
		if(y==h.begin())
		{
			cout<<-1;
		}
		else{
			y--;
			cout<<(*y);
			h.erase(y);
		}
		cout<<endl;
	}
	
	
	
}
