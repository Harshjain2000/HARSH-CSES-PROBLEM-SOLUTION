#include<bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	long long n,x,y,st,ed;
	cin>>x>>n;
	
	multiset<pair<long long ,long long> >rg;
	multiset<pair<long long ,long long> > :: iterator it;
	multiset<long long> rgl;
	rg.insert({0,x});
	rgl.insert(x);
	
	for(long long i=0;i<n;i++)
	{
		cin>>y;
		
		it = rg.upper_bound({y,0});
		it--;
		st = it->first;
		ed = it->second;
		rgl.erase(rgl.find(ed-st));
		rg.erase(it);
		
		rgl.insert(y-st);
		rgl.insert(ed-y);
		
		rg.insert({st,y});
		rg.insert({y,ed});
		
		cout<<*rgl.rbegin()<<" ";
	}
	return 0;
}
