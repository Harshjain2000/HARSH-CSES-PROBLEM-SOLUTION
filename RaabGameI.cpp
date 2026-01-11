#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long t;
	cin>>t;
	
	while(t--)
	{
		long long n,a,b,aa,bb;
		cin>>n>>a>>b;
		aa=a;bb = b;
		vector<long long >va(n),vb(n);
		if(a==0 && b==0)
		{	
			for(long long i=0;i<n;i++)
			{
				va[i] = i+1;
				vb[i] = i+1;
			}
		}
		else if(a==0 || b==0)
		{
			
		}
		else if((a+b)<=n)
		{
			long long i=1;
			if(a!=b)
			{
				if(a>b)
				{
					while(i<n && a>(b-1))
					{
						va[i-1] = i+1;
						vb[i-1] = i;
						i++;
						a--;
					}
					b--;
					va[i-1] = 1;
					vb[i-1] = i;
					i++; 
				}
				else if(a<b){
					while(i<n && (a-1)<b)
					{
						vb[i-1] = i+1;
						va[i-1] = i;
						i++;
						b--;
					}
					a--;
					vb[i-1] = 1;
					va[i-1] = i;
					i++; 
				}
			}
			if(a==b)
			{
				for(;i<=n;i++)
				{
					if(a!=0)
					{
						a--;
						va[i-1] = i;
						vb[i-1] = i+1;
						i++;
						if(i>n)
						{
							break;
						}
						vb[i-1] = i-1;
						va[i-1] = i;
					}
					else{
						va[i-1] = vb[i-1] = i;
					}
				}
			}
		}
		
		a = 0;b = 0;
		for(long long i=0;i<va.size();i++)
		{
			if(va[i]>vb[i])
			{
				a++;
			}
			else if(vb[i]>va[i]){
				b++;
			}	
		}
		if((aa==a) && (bb==b))
		{
			cout<<"YES\n";
			for(long long i=0;i<va.size();i++)
			{
				cout<<va[i]<<" ";
			}
			cout<<"\n";
			for(long long i=0;i<vb.size();i++)
			{
				cout<<vb[i]<<" ";
			}
			cout<<"\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	return 0;
}
