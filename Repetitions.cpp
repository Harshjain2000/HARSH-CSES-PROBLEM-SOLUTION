#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	
	long long ans=0,n=s.size();
	
	for(long long i=0,j=0;i<n;i++)
	{
		if(s[i]==s[j])
		{
			if(i==(n-1))
			{
				ans= max(ans, n-j);
			}
			continue;
		}
		ans = max(ans, i-j);
		j=i;
		i--;
	}
	cout<<ans;
	return 0;
}
