#include<bits/stdc++.h>
using namespace std;

void input(long long &n, vector<long long>&v)
{
	cin>>n;
	v.resize(n+1);
	v[1] =1;
	for(long long i=2;i<=n;i++)
	{
		cin>>v[i];	
	}
}



void print(vector<long long >&dp, long long l,long long r)
{
	for(long long i=l;i<r;i++)
	{
		cout<<dp[i]<<" ";
	}
}

void solve(long long &n, vector<long long>&v)
{
	map<long long ,long long>m;
	vector<long long >dp(n+1);
	
	for(long long i=1;i<=n;i++)
	{
		m[v[i]]++;
		m[i] += 0;
 	}
 	
 	queue<long long>q,q1;
	for (auto it:m)
	{
		if(it.second==0)
		{
			q.push(it.first);
		}
	}
	
	
	while(!q.empty())
	{
		long long tmp = q.front();
		q.pop();
		
		if(tmp==1)
		{
			continue;
		}
		m[v[tmp]]--;
		if(m[v[tmp]]==0)
		q1.push(v[tmp]);
		
		dp[v[tmp] ] += dp[tmp]+1;
		
		if(q.size()==0)
		{
			while(!q1.empty())
			{
				q.push(q1.front());
				q1.pop();
			}
		}
	}
	print(dp,1,n+1);
}

int main()
{
	long long n;
	vector<long long>v;
	
	input(n, v);
	
	solve(n, v);
		
	return 0;
}
