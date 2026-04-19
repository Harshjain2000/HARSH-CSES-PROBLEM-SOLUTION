#include<bits/stdc++.h>
using namespace std;

bool check(vector<string>&v, long long x, long long y)
{
	if(x<0 || y<0 || x>=v.size() || y>=v[0].size() || v[x][y]!='.')
	{
		return false;
	}
	return true;
}

bool endofmatrix(long long x,long long y, long long n,long long m)
{
	return (x==0 || y==0 || x==(n-1) || y==(m-1));
}

void print(vector<string>&v,long long sa,long long sb, long long ea,long long eb)
{
	if(ea==-1)
	{
		cout<<"NO";
		return ;
	}
	cout<<"YES"<<endl;
	if(ea==sa && eb==sb)
	{
		cout<<0;
		return ;
	}
	
	string ans="";
	while(!(ea==sa && eb==sb))
	{
		ans.push_back(v[ea][eb]);
		if(v[ea][eb]=='U')
		{
			ea = ea+1;
		}
		else if(v[ea][eb]=='D')
		{
			ea = ea-1;
		}
		else if(v[ea][eb]=='L')
		{
			eb = eb+1;
		}
		else{
			eb = eb-1;
		}
	}
	reverse(ans.begin(), ans.end());
	cout<<ans.size()<<"\n"<<ans;
}

int main()
{
	long long n,m,sa,sb,ea=-1,eb=-1;
	cin>>n>>m;
	
	vector<string>v(n);
	queue<pair<pair<long long, long long>, char > >q;
	
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];
		
		for(long long j=0;j<m;j++)
		{
			if(v[i][j]=='M')
			{
				q.push(make_pair(make_pair(i,j), 'M'));
			}
			else if(v[i][j]=='A')
			{
				sa=i;sb=j;
			}
		}
	}
	
	q.push(make_pair(make_pair(sa,sb), 'A'));
	vector<vector<int> >dpl = {{-1,0},{1,0},{0,1},{0,-1}};
	
	if(endofmatrix(sa, sb, n, m))
	{
		ea = sa;eb = sb;
	}
	
	while(!q.empty() && ea==-1)
	{
		pair<long long ,long long> tp = q.front().first;
		char val = q.front().second;
		q.pop();
		
		for(long long i=0;i<dpl.size();i++)
		{
			long long x = tp.first+dpl[i][0], y = tp.second+dpl[i][1];
			if(check(v,x,y))
			{
				if(dpl[i][0]==-1)
				{
					v[x][y] = 'U';	
				}
				else if(dpl[i][0]==1)
				{
					v[x][y] = 'D';
				}
				else if(dpl[i][1]==-1)
				{
					v[x][y] = 'L';
				}
				else{
					v[x][y] = 'R';
				}
				q.push(make_pair(make_pair(x,y),val));
				if(val=='A' && endofmatrix(x,y,n,m))
				{
					ea = x;eb= y;
					break;
				}
			}
		}	
	}
	print(v,sa,sb,ea,eb);
	
	return 0;
}
