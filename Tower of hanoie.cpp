#include<bits/stdc++.h>
using namespace std;

void func(long long n,long long a,long long b,long long c)
{
	if(n==0)
	{
		return ;
	}
	func(n-1, a,c,b);
	cout<<a<<" "<<c<<"\n";
	func(n-1, b,a,c);
}

long long count(long long n)
{
	if(n==0)
	{
		return 0;
	}
	return 1 + 2*count(n-1);
}

int main()
{
	long long n;
	cin>>n;
	cout<<count(n)<<"\n";
	func(n,1,2,3);
	
	return 0;
}
