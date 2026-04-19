#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
	long long n,k,ans=0,x;
	cin>>n>>k;
	
	map<long long,long long>m;
	
	queue<long long>q;
	
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		m[x]+=1;
		if(m[x]==1) ans++;
		q.push(x);
		
		if(q.size()==k)
		{
			cout<<ans<<" ";

			m[q.front()]--;
			
			if(m[q.front()]==0) ans--;
			q.pop();
		}
	}
	
}
