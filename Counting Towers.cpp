#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;
vector<long long> m1(1e6+1),m2(1e6+1);
void presolve()
{
	long long n = 1e6;
	
	m1[1] = 1;m2[1] = 1;
	
	for(long long i=2;i<=n;i++)
	{
		m1[i] = (2*m1[i-1] + m2[i-1])%mod;
		m2[i] = (4*m2[i-1] + m1[i-1])%mod;  	
	}	
}

void solve()
{
	long long n;
	cin>>n;
	
	cout<<(m1[n] + m2[n])%mod<<"\n";
}

int main()
{
	long long t;
	cin>>t;
	
	presolve();
	while(t--)
	{
		solve();
	}
	return 0;
}
