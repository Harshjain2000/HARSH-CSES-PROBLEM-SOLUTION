#include<bits/stdc++.h>
using namespace std;

#define mod (long long)(1e9+7)

int main()
{
	long long n,a,b,t;
	bool flag = true;
	cin>>n>>t;
	vector<pair<long long,long long > > v;
	for(long long i=0;i<n;i++)
	{
		cin>>a;
		v.push_back(make_pair(a,i+1));
	}
	
	sort(v.begin(), v.end());
	
	for(long long i=0;i<(n-2);i++)
	{
		long long l=i+1,r=n-1;
		
		while(l<r)
		{
			if((v[l].first+v[r].first+v[i].first) == t)
			{
				break;
			}
			else if((v[l].first+v[r].first + v[i].first) > t)
			{
				r--;
			}
			else{
				l++;
			}
		}
		if(l<r)
		{
			cout<<v[i].second<<" "<<v[l].second << " "<<v[r].second;flag = false;
			break;	
		}
		
	}	
	if(flag)
	{
		cout<<"IMPOSSIBLE";
	}
	return 0;
}
