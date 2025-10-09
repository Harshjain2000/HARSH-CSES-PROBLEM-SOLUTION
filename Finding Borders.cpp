#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	
	long long n = s.size(), len=0,j=0;
	
	vector<long long >dp(s.size());
	for(long long i=1;i<n;i++)
	{
		if(s[len]==s[i])
		{
			len++;j++;
		}
		else{
			if(len!=0){
				len = dp[len-1];
				i--;
				continue;
			}
		}
		dp[i] = len;
	}
	
	len = n/2;j = s.size()-1;
	vector<long long >ans;
	while(j>0 && dp[j]>0)
	{
		ans.push_back(dp[j]);
		j = dp[j]-1;
	}
	reverse(ans.begin(), ans.end());
	for(long long i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	
	return 0;
}
