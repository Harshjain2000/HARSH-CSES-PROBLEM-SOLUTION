#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long n,k,ans=0,x,a,b,c;
	
	cin>>n>>k>>x>>a>>b>>c;
	
	vector<long long>v(n);v[0]=x;
	for(long long i=1;i<n;i++) v[i] = (v[i-1] * a + b) % c;
	for(long long j=0;j<=31;j++){
		long long mx = -1;
		for(long long i=0;i<n;i++)
		{
			if(v[i] & (1ll << j)) mx = i+k-1;
			if(i >= k-1 && i <= mx) ans ^= 1ll<<j;
		}
	}
	cout << ans << "\n";
	return 0;
}
