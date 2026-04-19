#include<bits/stdc++.h>
using namespace std;

vector<long long > st;


long long fillst(vector<long long>&v, long long l , long long r, long long e)
{
	if(l>r)
	{
		return INT_MAX;
	}
	if(l==r)
	{
		st[e] = v[l];
		return st[e];
	}
	
	long long mid = l + ((r-l)>>1);
	
	st[e] = min(fillst(v, l, mid, 2*e+1), fillst(v, mid+1, r, 2*e+2));
	
	return st[e];
}

long long query(long long &a,long long &b, long long l,long long r, long long e)
{
	if(a<=l && r<=b)
	{
		return st[e];
	}
	
	if(r<a || l>b)
	{
		return INT_MAX;
	}
	long long mid = l + ((r-l)>>1);
	return min(query(a,b,l, mid,2*e+1), query(a,b,mid+1,r,2*e+2));
}

void solve(long long n)
{
	long long a,b;
	cin>>a>>b;
	a--;b--;
	cout<<query(a,b,0,n-1,0)<<endl;
}

int main()
{
	long long n,q;
	cin>>n>>q;
	
	vector<long long>v(n);
	
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];;
	}
	
	st.clear();
	st.resize((long long)pow(2, ceil(log2(n))+1)-1);
	
	fillst(v, 0 , n-1, 0);
	
	while(q--)
	{
		solve(n);
	}
}
