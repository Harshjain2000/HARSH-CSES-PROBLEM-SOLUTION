#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,a,b;
	cin>>n;
	
	multiset<long long>ms;
	set<long long>s;
	
	vector<pair<pair<long long,long long>,long long> >v;
	vector<long long> a1(n),a2(n);
	
	for(long long i=0;i<n;i++)
	{
		cin>>a>>b;
		v.push_back(make_pair(make_pair(a,b),i));
		ms.insert(b);
	}
	
	sort(v.begin(),v.end());
	
	for(long long i=0;i<n;i++)
	{
		auto it = ms.lower_bound(v[i].first.second);
		auto gt = it;
		gt++;
		if(it!=ms.begin() || (i!=0 && v[i].first.first==v[i-1].first.first))
		{
			a1[v[i].second] = 1;
		}
		else if(gt!=ms.end() && *(gt)==*(it)){
			a1[v[i].second] = 1;
		}
		
		auto jt = s.lower_bound(v[i].first.second);
		if(jt!=s.end() || (i!=(n-1) && v[i].first.first==v[i+1].first.first))
		{
			a2[v[i].second] = 1;
		}
		
		ms.erase(it);
		s.insert(v[i].first.second);
	}
	
	for(long long i=0;i<n;i++)
	{
		cout<<a1[i]<<" ";
	}
	cout<<endl;
	
	for(long long i=0;i<n;i++)
	{
		cout<<a2[i]<<" ";
	}
	
	return 0;
}
