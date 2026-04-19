#include<bits/stdc++.h>
using namespace std;


class Compare {
public:
    bool operator()(pair<long long,long long >a, pair<long long,long long >b)
	{
		return a.first==b.first? a.second>b.second:a.first<b.first;	
	}
};
 

 
int main()
{
	long long n,k,ans=0,x;
	cin>>n>>k;
	
	priority_queue<pair<long long,long long>, vector<pair<long long,long long> > , Compare >pq;
	queue<long long>q;
	map<long long,long long>m;
	
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		m[x]++;
		q.push(x);
		pq.push(make_pair(m[x],x));
		
		if(q.size()==k)
		{
			while(!pq.empty() && pq.top().first!=m[pq.top().second])
			{
				pq.pop();
			}
			cout<<pq.top().second<<" ";
			
			m[q.front()]--;
			q.pop();
		}
	}
	
}
