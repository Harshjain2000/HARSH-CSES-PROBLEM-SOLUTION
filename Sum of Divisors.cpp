#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,m=1e9+7,sum=0;
	cin>>n;
	
	for(long long i=1;i<=sqrt(n);i++)
	{
		if((n%i)==0)
		{
			sum += (i + (n/i));
			if(i==(n/i))
			{
				sum -= i;
			}
		}
		
		sum = sum%m;
	}
	
	cout<<sum;
	
	return 0;
}
