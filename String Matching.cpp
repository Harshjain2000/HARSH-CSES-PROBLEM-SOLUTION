#include<bits/stdc++.h>
using namespace std;


long long solve(string a, long long len)
{
	long long count=0, N=a.size();
	
	vector<long long > prefix(N);
	
	for(long long i=1;i<N;i++)
	{
		long long tmp = prefix[i-1];
		
		while(tmp>0 && a[i]!=a[tmp])
		{
			tmp = prefix[tmp-1];
		}
		
		if(a[i]==a[tmp])
		{
			tmp++;
		}
		prefix[i] = tmp;
		
		if(tmp==len)
		{
			count++;
		}
	}
	
	return count;
}

int main()
{
	string a, b;
	
	cin>>a>>b;
	
	cout<<solve(b+"#"+a, b.size());
	return 0;
}
