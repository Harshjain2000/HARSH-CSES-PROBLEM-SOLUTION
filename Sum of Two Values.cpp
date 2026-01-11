#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,x,a;
	cin>>n>>x;
	vector<pair<long long,long long> >v(n);
	
	for(long long i=0;i<n;i++)
	{
		cin>>a;
		v[i] = make_pair(a,i+1);
	}
	
	sort(v.begin(), v.end());
	
	long long l=0, r=n-1;
	
	while(r>l)
	{
		long long y = (v[l].first + v[r].first);
		if(y==x)
		{
			break;
		}
		else if(y>x)
		{
			r--;
		}
		else{
			l++;
		}
	}
	
	if(r<=l)
	{
		cout<<"IMPOSSIBLE";
	}
	else{
		cout<<v[l].second<<" "<<v[r].second;
	}
	
}
