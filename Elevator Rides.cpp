#include<bits/stdc++.h>
using namespace std;

void input(long long &n,long long &x,vector<long long >&v)
{
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];
	}
}


long long solve(long long &n,long long &x,vector<long long >&w)
{
	long long limit = 1<<n;
    vector<pair<long long,long long> > dp(limit, {n + 1, 0});
    dp[0] = {1, 0};
    
	    
	  for (long long s=1; s < limit; s++) {
	    for (long long person=0; person < n; person++) {
	      if (s & (1 << person)) {
	        pair<long long, long long> tmp = dp[s ^ (1 << person)];
	
	        if (tmp.second + w[person] <= x) {
	          tmp.second += w[person];
	        }
	        else {
	          tmp.first += 1;
	          tmp.second = w[person];
	        }
	
	        dp[s] = min(dp[s], tmp);
	      }
	    }
	  }
	
	  return dp[limit - 1].first;
}

int main()
{
	long long n, x;
	cin>>n>>x;
	
	vector<long long>v(n);
	
	input(n,x,v);
	
	cout<<solve(n,x,v);
	
		
	return 0;
}
