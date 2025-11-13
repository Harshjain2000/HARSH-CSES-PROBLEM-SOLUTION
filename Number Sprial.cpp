#include<bits/stdc++.h>
using namespace std;


long long solve(long long &y, long long &x)
{
	long long dt =max(y,x);
	
	long long l=((dt-1)*(dt-1))+1,r=dt*dt;
	
	
	if((r%2) == 0)
	{
		if(y==max(y,x))
		{
			return r-x+1;
		}
		else{
			return l+y-1; 
		}
	}
	else{
		if(y==max(y,x))
		{
			return l+x-1;
		}
		else{
			return r-y+1; 
		}
	}
}

int main()
{
	long long t;
	cin>>t;
	
	while(t--){
		long long y,x;
		cin>>y>>x;
		
		cout<<solve(y,x)<<"\n";
	}
}
