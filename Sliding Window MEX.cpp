#include<bits/stdc++.h>
using namespace std;

 
int main()
{
	long long n,k,ans=0,x;
	cin>>n>>k;
	
	priority_queue<long long, vector<long long> , greater<long long> >pq;
	queue<long long>q;
	map<long long,long long>m;
	
	for(long long i=0;i<=n;i++)
	{
		pq.push(i);
	}
	
	
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		m[x]++;
		q.push(x);
		
		if(q.size()==k)
		{
			while(!pq.empty() && m[pq.top()])
			{
				pq.pop();
			}
			cout<<pq.top()<<" ";
			
			
			if(m[q.front()]==1)
			{
				pq.push(q.front());
			}
			m[q.front()]--;
			q.pop();
		}
	}
	
}
