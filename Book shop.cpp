#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,x;
	cin>>n>>x;
	
	vector<long long > price(n), pages(n);
	
	for(long long i=0;i<n;i++)
	{
		cin>>price[i];
	}
	for(long long i=0;i<n;i++)
	{
		cin>>pages[i];
	}
	
	vector<vector<long long> >dp(2, vector<long long>(x+1));
	
	for(long long i=0;i<=n;i++) //loop's over books
	{
		for(long long j=0;j<=x;j++) // loop's over bound of max price
		{
			if(i==0)
			{
				dp[i%2][j] = 0;
			}
			else if(j==0)
			{
				dp[i%2][j] = 0;
			}
			else{
				dp[i%2][j] = dp[(i-1)%2][j];
				if(j>=price[i-1])
				{
					dp[i%2][j] = max(dp[i%2][j], pages[i-1] + dp[(i-1)%2][j-price[i-1]]);
				}
			}
		//	cout<<dp[i%2][j]<<" ";
		}
	//	cout<<endl;
	}
	
	cout<<dp[n%2][x];
	return 0;
}
