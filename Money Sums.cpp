#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long n,x;
	cin>>n;
	
	map<long long,long long > m;
	m[0] = 1;
	
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		for (auto it = m.rbegin(); it != m.rend(); ++it) 
		{
			m[it->first + x] ++;
		}
	}
	long long count=0;
	for(auto it:m)
	{
		count++;
	}
	cout<<count-1<<"\n";
	for(auto it :m)
	{
		if(it.first==0)
		{
			continue;
		}
		cout<<it.first<<" ";
	}
	
	
}
