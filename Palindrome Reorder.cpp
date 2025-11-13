#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	
	map<char, int>m;
	
	for(int i=0;i<s.size();i++)
	{
		m[s[i]-'0']++;
	}
	
	
	int flag = 0;
	string ans = "", extra="";
	for(auto it:m)
	{
		if(it.second%2)
		{
			flag++;
			if(flag == 2)
			{
				break;
			}
			extra += (char)it.first+'0';
		}
		for(long long i=0;i<(it.second-1);i+=2)
		{
			ans += (char)(it.first + '0');
		}
	}
	
	if(flag == 2)
	{
		cout<<"NO SOLUTION";
	}
	else{
		string bans = ans;
		reverse(bans.begin(), bans.end());
		cout<<ans + extra+ bans;
	}
	return 0;
	
}
