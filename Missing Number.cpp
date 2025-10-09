#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,num=0,x;
	cin>>n;
	
	for(long long i=0;i<n;i++)
	{
		num = num^(i+1);
		if(i==0)
		{
			continue;
		}
		cin>>x;
		num = num^x;
	}
	
	cout<<num;
	
	return 0;
}
