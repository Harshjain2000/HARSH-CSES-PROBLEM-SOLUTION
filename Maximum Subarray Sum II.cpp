#include<bits/stdc++.h>
using namespace std;

void input(long long &n,long long &a,long long &b,vector<long long >&v)
{
	cin>>n>>a>>b;
	v.clear();
	v.resize(n);
	
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];
	}
	
	return ;
}

long long solve(long long &N,long long &A, long long &B,vector<long long>&arr)
{
	deque<long long> dq;
    vector<long long> prefixSum(N + 1);
	long long ans = LLONG_MIN;

    for (int i = 1; i <= N; i++) {
        prefixSum[i] += prefixSum[i - 1] + arr[i - 1];
    }

    for (int i = 1; i < B; i++) {
        while (!dq.empty()
            && prefixSum[dq.front()] <= prefixSum[i]) {
            dq.pop_front();
        }
        dq.push_front(i);
    }

    for (int i = 0; i <= (N - A); i++) {
    while (i + B <= N && !dq.empty()
            && prefixSum[dq.front()]
                    <= prefixSum[i + B]) {
            dq.pop_front();
        }

        if (i + B <= N)
            dq.push_front(i + B);

        while (!dq.empty() && dq.back() < (A + i)) {
            dq.pop_back();
        }
        ans = max(ans, prefixSum[dq.back()] - prefixSum[i]);
    }
    return ans;
}

int main()
{
	long long n,a,b;
	vector<long long>v;
	
	input(n,a,b,v);
	
	cout<<solve(n,a,b,v);
	return 0;
}
