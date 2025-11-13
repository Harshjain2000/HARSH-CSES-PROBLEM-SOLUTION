#include<bits/stdc++.h>
using namespace std;


long long solve(long long &n)
{
	return ((n*n)*(n*n-1))/2 - 4*(n-1)*(n-2);
}

int main()
{
	long long n;
	cin>>n;
	
	for(long long i=1;i<=n;i++)
	{
		cout<<solve(i)<<"\n";
	}
	return 0;
}
