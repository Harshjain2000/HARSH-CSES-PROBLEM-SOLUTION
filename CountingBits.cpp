#include<bits/stdc++.h>
using namespace std;


void input(long long &n)
{
	cin>>n;
}

long long CountingBits(long long &n)
{
	long long ans=0;
	while(n>1)
	{
		long long tmp = 0,count=0,twopow=1;
//		cout<<n<<"\n";
		while(n>1)
		{
			tmp = tmp + twopow*(n%2);
			n /= 2;
			twopow*=2;
			count++;
		}
//		cout<<n<<" "<<" \n";
		ans += (tmp + 1 + count*(1ll<<count-1)); 
//		cout<<ans<<" "<<tmp<<"\n   ----";
		n = tmp;
	}
	
	return ans+n;
}

int main()
{
	long long n;
	input(n);
	
	cout<<CountingBits(n);

	return 0;
}
