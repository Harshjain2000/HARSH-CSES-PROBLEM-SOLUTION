#include<bits/stdc++.h>
using namespace std;

long long val;

long long q1(long long i)
{
	cout<<"F "<<i<<endl;
	cin>>val;
	
	return val;
}

long long q2(long long i)
{
	cout<<"S "<<i<<endl;
	cin>>val;
	
	return val;
}

int main()
{
	long long n,k,mid,mid2,v1,v2,ans=-1;
	cin>>n>>k;
	long long l=1,r=min(n,k),l2=1,r2=n,l2t=1,r2t=n;
	
	if(k==1)
	{
		ans = max(q1(1),q2(1));
	}
	else if(k<=n && q1(k)>q2(1))
	{
		ans = q1(k);
	}
	else if(k<=n && q2(k)>q1(1))
	{
		ans = q2(k);
	}
	else
	while(l<=r)
	{
		mid = l + ((r-l)>>1);
		v1 = q1(mid);
		if((k-mid)>0 && ((k-mid)<=n))
		{
			v2 = q2(k-mid);
			if(v1<v2)
			{
				if((k-mid+1)<=n)
				{
					l2 = q2(k-mid+1);
					if(v1>l2)
					{
						ans = v1;
						break;
					}
					else{
						r = mid-1;
					}
				}
				else{
					ans = v1;
					break;
				}
			}
			else{
				if((mid+1)<=n)
				{
					l2 = q1(mid+1);
					if(v2>l2)
					{
						ans = v2;
						break;
					}
					else{
						l = mid+1;
					}
				}	
				else{
					ans = v2;
					break;
				}
			}
		}
		else{
			l = mid+1;
		}
				
	}
	
	cout<<"! "<<ans<<endl;
	return 0;
}
