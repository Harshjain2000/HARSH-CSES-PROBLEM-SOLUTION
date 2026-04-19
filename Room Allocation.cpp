#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,a,b,ans=0;
	cin>>n;
	
	vector<pair<pair<long long ,long long>,long long> >v;
	vector<long long >result(n);
	for(long long i=0;i<n;i++)
	{
		cin>>a>>b;
		v.push_back(make_pair(make_pair(a,b),i));
	}
	
	sort(v.begin(),v.end());
	priority_queue<pair<long long,long long>, vector<pair<long long,long long> > , greater<pair<long long,long long> > >pq;	
	priority_queue<long long, vector<long long> , greater<long long> >gq;
	
	for(long long i=0;i<n;i++)
	{
		gq.push(i+1);
	}
	
	for(long long i=0;i<n;i++)
	{
		while(!pq.empty() && (pq.top().first<v[i].first.first))
		{
			gq.push(pq.top().second);
			pq.pop();
		}
		pq.push(make_pair(v[i].first.second, gq.top()));
		ans = max(ans, (long long)pq.size());
		result[v[i].second] = gq.top();
		gq.pop();
	}
	
	cout<<ans<<endl;
	
	for(long long i=0;i<n;i++)
	{
		cout<<result[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
	
}
