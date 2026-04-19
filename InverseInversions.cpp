#include<bits/stdc++.h>
using namespace std;

#define ll long long 


void Inverseinversion(ll &n,ll &k)
{
	ll count=  (1+ sqrt(1+8*k))/2;
	ll rem = k - (count*(count-1))/2;                              
	
	for(long long i=0;i<(n-count-1);i++)
	{
		cout<<(i+1)<<" ";
	}
	
	
	for(long long counter=n;counter>(n-count);counter--)
	{
		if(rem!=0 && rem==(n-counter))
		cout<<n-count<<" ";
		
		cout<<counter;
		
		cout<<" ";
	}
	
	return;
}


void solve()
{
	long long n,k;
	cin>>n>>k;	
	Inverseinversion(n,k);
	return ;
}

int main()
{
	solve();
	
	return 0;
}
