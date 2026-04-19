#include<bits/stdc++.h>
using namespace std;

bool query(long long x)
{
	cout<<"? "<<x<<endl;
	
	string val;
	cin>>val;
	
	return val=="YES";
}

int main()
{
	long long l=1,r=(long long)1e9,mid;
	
	while(l<r)
	{
		mid = l+ ((r-l)>>1);
		
		if(query(mid))
		{
			l = mid+1;
		}
		else 
		{
			r = mid;
		}
	}
	
	cout<<"! "<<r<<endl;
}
