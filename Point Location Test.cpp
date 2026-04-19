#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		
		
		long long val = (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);
		
		val==0?cout<<"TOUCH":val>0?cout<<"LEFT":cout<<"RIGHT";
		cout<<endl;
	}
	
	return 0;
}
