#include<bits/stdc++.h>
using namespace std;

string solve(long long &a, long long &b)
{
	if(a<b)
	{
		return solve(b,a);
	}
	long long val = a-b;
	
	if(val>b)
	{
		return "NO";
	}
	val = b-val;
	
	if(val%3)
	{
		return "NO";
	}
	else{
		return "YES";
	}
}

int main()
{
	long long t;
	cin>>t;
	
	while(t--)
	{
		long long a,b;
		cin>>a>>b;
		
		cout<<solve(a, b)<<"\n";
	}
}
