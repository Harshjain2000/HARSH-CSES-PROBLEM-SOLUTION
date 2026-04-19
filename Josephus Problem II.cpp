#include<bits/stdc++.h>
using namespace std;

void input(long long &n, long long &k)
{
	cin>>n>>k;
}

void solve(long long &n,long long &k)
{
	vector<vector<long long> >v;
	vector<long long>va;
	
	long long j=0,tmp = sqrt(n), nval,cl=0;
	for(long long i=1;i<=n;i++)
	{
		va.push_back(i);
		
		if(va.size()>=tmp)
		{
			v.push_back(va);
			va.clear();
		}
	}
	if(va.size()!=0)
	{
		v.push_back(va);
		va.clear();
	}
	j=0;
	for(long long i=1;i<=n;i++)
	{
		nval = k%(n-i+1);
		while(nval)
		{
			if((v[j].size()-cl)<=nval)
			{
				nval -= (v[j].size()-cl);
				j++;
				cl=0;
			}
			else{
				cl += nval;
				nval = 0;
			}
			if(j==v.size())
			{
				j=0;
			}
		}
		while(v[j].size()<=cl)
		{
			j++;
			cl=0;
			if(j==v.size())
			{
				j=0;
			}
		}
		cout<<v[j][cl]<<" ";
		
		v[j].erase(v[j].begin()+cl);
		while(i!=n && v[j].size()==cl)
		{
			j++;cl=0;
			if(j==v.size())
			{
				j=0;
			}
		}
	}
}

int main()
{
	long long n,k;
	input(n,k);
	solve(n,k);
	
	return 0;
}
