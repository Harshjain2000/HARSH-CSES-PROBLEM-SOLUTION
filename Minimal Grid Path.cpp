#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	
	string ans = "";	
	vector<string>v(n);
	
	
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];
	}
	
	vector<pair<long long,long long> >curpos,nextpos;curpos.push_back(make_pair(0,0));
	ans = ans + v[0][0];
	
	while(curpos.size()>0)
	{
		nextpos.clear();
		long long np = 250;
		for(auto p:curpos)
		{
			if((p.first+1)<n)
			{
				np = min(np, (long long)v[p.first+1][p.second]);
			}
			if((p.second+1)<n)
			{
				np = min(np, (long long)v[p.first][p.second+1]);
			}
		}
		for(auto p: curpos)
		{
			if((p.first+1)<n && (np==v[p.first+1][p.second]) && (nextpos.size()==0 || (make_pair(p.first+1, p.second) != nextpos[nextpos.size()-1])))
			{
				nextpos.push_back(make_pair(p.first+1,p.second));		
			}
			if((p.second+1)<n && (np==v[p.first][p.second+1])  && (nextpos.size()==0 || (make_pair(p.first, p.second+1) != nextpos[nextpos.size()-1])))
			{
				nextpos.push_back(make_pair(p.first,p.second+1));
			}
		}
		curpos = nextpos;
		if(curpos.size()==0)
		{
			break;
		}

		ans += (char)np;
	}
	cout<<ans;
}
