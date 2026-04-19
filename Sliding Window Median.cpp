#include<bits/stdc++.h>
using namespace std;


void remove1(multiset<long long> &a, multiset<long long> &b,long long &x)
{
	if((*a.rbegin()) >= x)
	{
		a.erase(a.find(x));
	}
	else{
		b.erase(b.find(x));
	}
	
	if(((long long)a.size()-2ll)>=(long long)b.size())
	{
		b.insert(*a.rbegin());
		a.erase(--a.end());
	}
	
	if(((long long)b.size()-1ll)>=(long long)a.size())
	{
		a.insert((*b.begin()));
		b.erase(b.begin());
	}
	
}

void insert(multiset<long long> &a, multiset<long long> &b,long long &x)
{
	if(a.empty())
	{
		a.insert(x);return ;
	}
	if(b.empty())
	{
		if((*a.rbegin()) > x)
		{
			a.insert(x);
			b.insert(*a.rbegin());
			a.erase(--a.end());
		}
		else
		b.insert(x);return ;
	}
	if((*a.rbegin()) < x)
	{
		b.insert(x);
	}
	else{
		a.insert(x);
	}
	
	if(((long long)a.size()-2ll)>=(long long)b.size())
	{
		b.insert(*a.rbegin());
		a.erase(--a.end());
	}
	
	if(((long long)b.size()-1ll)>=(long long)a.size())
	{
		a.insert((*b.begin()));
		b.erase(b.begin());
	}
	
}
 
int main()
{
	long long n,k,ans=0,x;
	cin>>n>>k;
	
	multiset<long long>sl,sr;
	
	queue<long long>q;
	
	
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		q.push(x);
		insert(sl,sr,x);
		
		if(q.size()==k)
		{
			cout<<(*sl.rbegin())<<" ";
			remove1(sl,sr,q.front());
			q.pop();
		}
		
	}
	
	return 0;
	
}
