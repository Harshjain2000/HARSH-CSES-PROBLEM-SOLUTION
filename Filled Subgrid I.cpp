#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n, l,m;
	cin>>n>>l;
	m=n;
	
	vector<long long >ans(26,0);
	
	vector<string>v(n);
	vector<vector<int> >dp(n+1, vector<int>(m+1));
	
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];
	}
	
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			int cur = max(dp[i-1][j-1]-1, max(dp[i-1][j]-1,dp[i][j-1]-1));
			cur = max(1,cur);
			
			bool flag = true;
			while(flag)
			{
				int newcur = cur+1;
				
				if(((newcur+j-1)>m) || (newcur+i-1)>n)
				{
					break;
				}
				for(int k=0;k<newcur;k++)
				{
			//		cout<<i<<" "<<j<<" "<<k<<" "<<newcur<<" "<<i+k-1<<" "<<j+newcur-2<<" "<<endl;
					if(v[i-1][j-1] != v[i+k-1][j+newcur-2])
					{
						flag = false;break;
					}
					if(v[i-1][j-1] != v[i+newcur-2][j+k-1])
					{
						flag = false;break;
					}
				}
				if(flag)
				cur = newcur;
			}
			dp[i][j] = cur;
			ans[v[i-1][j-1]-'A'] += cur;
		//	cout<<v[i-1][j-1]<<" "<<ans[v[i-1][j-1]-'A']<<endl;
		}
	}
	
	for(long long i=0;i<26;i++)
	{
		if(ans[i]!=0)
		{
			cout<<ans[i]<<"\n";
		}	
	}
		
	return 0;
}
