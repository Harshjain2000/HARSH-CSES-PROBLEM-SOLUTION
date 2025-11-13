#include<bits/stdc++.h>
using namespace std;


long long solve(vector<long long > &v,long long &n )
{
	if(n==0)
	{
		return 0;
	}
	long long len=1;
	
	vector<long long> lastele = {v[0]};
	
	for(long long i=1;i<n;i++)
	{
		long long l = 0, r=len-1;
		
		while(l<=r)
		{
			long long mid = l + ((r-l)>>1);
			
			if(lastele[mid] >= v[i])
			{
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		
		if(l==len){
			lastele.push_back(v[i]);
			len++;
		}
		else if((r+1)<len && v[i]<lastele[r+1]){
			lastele[r+1] = v[i];
			
		}

	}
	
	
	return len;
	
}

int main()
{
	long long n;
	cin>>n;
	
	vector<long long >v(n);
	
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];
	}
	
	cout<<solve(v,n);
}
