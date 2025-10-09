#include<bits/stdc++.h>
using namespace std;


vector<long long> getarr(string &s)
{
	long long n=s.size();
	vector<long long>z(n);

	long long l=0,r=0;	
	for(long long i=1;i<n;i++)
	{
		long long idx = i,k;
		if(i<=r)	
		{
			k = i-l;
			
			z[i] = min(z[k], r-i+1);
		}
		
		while((i+z[i])<n && s[z[i]]==s[i+z[i]])
		{
			z[i]++;
		}
		
		
		if(r < (i+z[i]-1))
		{
			l = i;
			r = i+z[i]-1;
		}
	//	cout<<i<<" "<<z[i]<<endl;
	}
	
	return z;
}

int main()
{
	string s;
	cin>>s;
	
	long long n = s.size();
	vector<long long>zarr = getarr(s);
	
	for(long long i=0;i<zarr.size();i++)
	{
		if(zarr[i] == (n-i))
		{
			cout<<i<<" ";
		}
	}
	cout<<n<<" ";
	
	return 0;
}
