#include<bits/stdc++.h>
using namespace std;



int main()
{
	long long n,a,b,ans=0;
	cin>>n;
	
	vector<pair<long long,long long> >v;
	
	for(long long i=0;i<n;i++)
	{
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(),  v.end());	
	
	priority_queue<long long, vector<long long> , greater<long long> >pq;
	
	for(long long i=0;i<v.size();i++)
	{
		while(!pq.empty() && pq.top()<=v[i].first)
		{
			pq.pop();
		}
		pq.push(v[i].second);
		
		ans = max(ans,(long long) pq.size());
	}
	
	cout<<ans;
	
	return 0;
	
}
