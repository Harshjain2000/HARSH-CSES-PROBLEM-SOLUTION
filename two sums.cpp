#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	vector<long long>v(n);
	
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];
	}
	
	sort(v.begin(), v.end());
	
	long long i=0, j=n-1;
	
	while(r>l)
	{
		long long y = (v[l] + v[r]);
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
		cout<<v[l]<<" "<<v[r];
	}
	
	cout<<ans;
}
