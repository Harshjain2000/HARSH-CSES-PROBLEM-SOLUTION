#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	
	vector<vector<long long> > v(n,vector<long long>(3));
	
	for(long long i=0;i<n;i++)
	{
		cin>>v[i][0]>>v[i][1]>>v[i][2];
		
	}
	
	sort(v.begin() , v.end());
	
	priority_queue<pair<long long ,long long>,  vector<pair<long long, long long> >,greater<pair<long long,long long> > >pq;
	
	long long tmp = 0;
	for(long long i=0;i<n;i++)
	{
		while(!pq.empty() && pq.top().first<v[i][0])
		{
			tmp = max(tmp, pq.top().second);
			pq.pop();
		}
		pq.push(make_pair(v[i][1],tmp+ v[i][2]));
	}
	
	while(!pq.empty())
	{
		tmp = max(tmp, pq.top().second);
		pq.pop();
	}
	
	cout<<tmp;
	
	return 0;
}
