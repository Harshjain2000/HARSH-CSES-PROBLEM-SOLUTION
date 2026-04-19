#include<bits/stdc++.h>
using namespace std;


vector<long long >ans;

bool query(long long i,long long j)
{
	cout<<"? "<<i<<" "<<j<<endl;
	
	string val;
	cin>>val;
	
	return val=="YES";
}

void helper(long long &n, long long l,long long r)
{
	if(l==r)
	{
		return ;	
	}	
	long long mid = l + ((r-l)>>1);
	
	helper(n, l,mid);
	helper(n, mid+1, r);

	vector<long long >tmp(r-l+1);
	
	long long j=mid+1,i=l;
	for(long long k=0;k<(r-l+1);k++)
	{
		if(j>r)
		{
			tmp[k] = ans[i-1]; 
			i++;
		}
		else if((i<=mid) && query(ans[i-1],ans[j-1]))
		{
			tmp[k] = ans[i-1];
			i++;
		}
		else{
			tmp[k] = ans[j-1];
			j++;
		}
	}
	
	for(long long k=0;k<(r-l+1);k++)
	{
		ans[k+l-1] = tmp[k];
	}
	
	return ;
}

int main()
{
	long long n;
	cin>>n;
	
	ans.clear();ans.resize(n);
	
	for(long long i=0;i<n;i++)
	{
		ans[i] = i+1;
	}

	helper(n,1,n);
	
	vector<long long> res(n);
	for(long long i=0;i<n;i++)
	{
		res[ans[i]-1] = i+1;
	}
	
	cout<<"! ";
	
	for(long long i=0;i<n;i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
}
