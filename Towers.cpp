#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,x,len=0;
	cin>>n;
	
	vector<long long >v;
	
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		
		vector<long long> ::iterator it = upper_bound(v.begin(), v.end(),x);
		
		if(it != v.end())
		{
			*it = x;
		}
		else{
			v.push_back(x);
			len++;
		}
	}
	
	cout<<len;
	
	return 0;
}
