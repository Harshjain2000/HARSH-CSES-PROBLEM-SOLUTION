#include<bits/stdc++.h>
using namespace std;

#define mod (long long)(1e9+7)

int main()
{
	long long n,counter=1;
	cin>>n;
	
	queue<long long>q;
	
	for(long long i=0;i<n;i++)
	{
		q.push(i+1);
	}
	
	while(!q.empty())
	{
		q.push(q.front());
		q.pop();
		
		cout<<q.front()<<" ";
		q.pop();
	}
	
	return 0;
}
