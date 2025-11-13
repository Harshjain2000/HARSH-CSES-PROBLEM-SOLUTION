#include<bits/stdc++.h>
using namespace std;


void print(vector<string>&a)
{
	for(long long i=0;i<a.size();i++)
	{
		cout<<a[i]<<"\n";
	}
}

void solve(long long &n)
{
	vector<string>ans = {"0","1"};
	if(n==1)
	{
		print(ans);
		return ;
	}
	
	
	for(long long i=2;i<=n;i++)
	{
		long long len = ans.size();
		
		for(long long j=len-1;j>=0;j--)
		{
			ans.push_back("1" + ans[j]);
			ans[j] = "0" + ans[j];	
		}	
	}
	print(ans);
	return ;
}

int main()
{
	long long n;
	cin>>n;
	
	solve(n);
}
