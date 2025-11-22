#include<bits/stdc++.h>
using namespace std;


string s;
vector<vector<bool > >vis(7,vector<bool>(7,false));

void input()
{
	cin>>s;
}

long long helper( long long idx, long long x,long long y)
{
	if(idx == s.size())
	{
		return (x==6 && y==0);
	}
	
	if(x==6 && y==0)
	{
		return 0;
	}
	
	if(x<0 || y<0 || x>=7 || y>=7  || vis[x][y] 
	|| ((x<6 && x>0 && y>0 && y<6) && ((vis[x+1][y] && vis[x-1][y] && !vis[x][y+1] && !vis[x][y-1]) 
	|| (!vis[x+1][y] && !vis[x-1][y] && vis[x][y+1] && vis[x][y-1]) ||  (vis[x-1][y+1] && !vis[x-1][y] && !vis[x][y+1]) ||  (vis[x+1][y-1] && !vis[x][y-1] && !vis[x+1][y]) ) )
	|| ((x>0 &&y>0) && (vis[x-1][y-1] && !vis[x-1][y] && !vis[x][y-1]) )
	|| ((x<6 && y<6) && (vis[x+1][y+1] && !vis[x+1][y] && !vis[x][y+1]) ) 
	
	)
	
	{
		return 0;
	}

	
	


	vis[x][y] = true;
	long long ans = 0;
	if(s[idx]=='D' || s[idx]=='?')
	{
		ans += helper(idx+1, x+1,y);
	}
	
	if(s[idx]=='U' || s[idx]=='?')
	{
		ans += helper(idx+1, x-1,y);
	}
	
	if(s[idx]=='L' || s[idx]=='?')
	{
		ans += helper(idx+1, x,y-1);
	}
	
	if(s[idx]=='R' || s[idx]=='?')
	{
		ans += helper(idx+1, x,y+1);
	}
	vis[x][y] = false;
	
	return ans;
}

long long solve()
{

	return helper( 0, 0, 0);
}

int main()
{
	input();
	cout<<solve();
}
