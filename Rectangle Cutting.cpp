#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long A,B;
	cin>>A>>B;
	
	vector<vector<int> > dp(A + 1, vector<int>(B + 1, 1e9));
    for (int i = 0; i <= A; i++) {
        for (int j = 0; j <= B; j++) {
            if (i == j) {
                dp[i][j] = 0;
            }
            else {
                for (int k = 1; k < j; k++) {
                    dp[i][j]
                        = min(dp[i][j],
                              dp[i][k] + dp[i][j - k] + 1);
                }
                for (int k = 1; k < i; k++) {
                    dp[i][j]
                        = min(dp[i][j],
                              dp[k][j] + dp[i - k][j] + 1);
                }
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
	cout<<dp[A][B];
	return 0;
}
