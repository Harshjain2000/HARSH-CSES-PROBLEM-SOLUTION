#include<bits/stdc++.h>
using namespace std;


void solve(long long &n)
{
	if((((n*(n+1))/2 )%2) !=0	)
	{
		cout<<"NO";
		return ;
	}
	
	long long sum = (n*(n+1)/2)/2;
	
	set<long long>s1,s2;
	for(long long i=n;i>0;i--)
	{
		if(sum>=i)
		{
			s1.insert(i);
			sum -= i;
		}
		else{
			s2.insert(i);
		}
	}
	cout<<"YES\n";
	cout<<s1.size()<<"\n";
	for(auto it:s1)
	{
		cout<<it<<" ";
	}
	cout<<"\n";
	
	cout<<s2.size()<<"\n";
	for(auto it:s2)
	{
		cout<<it<<" ";
	}
	cout<<"\n";
}

int main()
{
	long long n;
	cin>>n;
	
	
	solve(n);
	return 0;
}
