#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;
vector<vector<long long > >dp(1001,vector<long long> (2049,-1));

void input(long long &n,long long &m)
{
	cin>>n>>m;
}

void getnextmask(long long &n,long long mask,long long newmask,long long j,vector<long long>&allmask)
{
	if(j==n)
	{
		allmask.push_back(newmask);
		return;
	}
	
	//2X1
	if(j<(n-1) && !((1<<j) &mask) && !((1<<(j+1) &mask)) )
	{
		getnextmask(n,mask,newmask, j+2,allmask);
	}
	//1X2
	if(!((1<<j) &mask) )
	{
		getnextmask(n,mask,newmask+(1<<j), j+1,allmask);
	}
	//already filled check
	if((1<<j) &mask)
	{
		getnextmask(n,mask,newmask, j+1,allmask);
	}
}

long long helpercounttiles(long long &n,long long &m, long long i,long long mask)
{
	if(i==m)
	{
		return mask==0;
	}
	
	if(dp[i][mask]!=-1)
	{
		return dp[i][mask];
	}
	long long ans =0;
	vector<long long >allmask;
	getnextmask(n,mask,0,0, allmask);
	
	for(auto it:allmask)
	{
		ans = (ans + helpercounttiles(n,m, i+1, it))%mod;
	}
	
	dp[i][mask] = ans;
	
	return ans;
}

long long solve(long long &n,long long &m)
{
	return helpercounttiles(n,m,0,0);
}

int main()
{
	long long n,m;
	
	input(n,m);
	cout<<solve(n,m);
	return 0;
}
