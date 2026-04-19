#include<bits/stdc++.h>
using namespace std;


long long func(stack<long long>&a,stack<long long>&b, long long &x)
{
	if(a.top()<x)
	{
		return -1;
	}
	else{
		if(b.top()>x)
		{
			b.push(x);
			return 2;
		}
		else{
			a.push(x);
			return 1;
		}
	}

}

int main()
{
	long long n, x=1,val=0;
	cin>>n;
	
	vector<long long >input(n),ans;
	stack<long long>s1,s2;
	
	for(long long i=0;i<n;i++)
	{
		cin>>input[i];
	}
	
	for(long long i=0;i<n;i++)
	{
		if(x==input[i])
		{
			ans.push_back(1);
			x++;
		}
		else{
			if(s1.empty() && s2.empty())
			{
				s1.push(input[i]);
				ans.push_back(1);
			}
			else if(s1.empty()){
				if(s2.top()>input[i])
				{
					s2.push(input[i]);
					ans.push_back(2);
				}
				else{
					s1.push(input[i]);
					ans.push_back(1);
				}
			}
			else if(s2.empty())
			{
				if(s1.top()>input[i])
				{
					s1.push(input[i]);
					ans.push_back(1);
				}
				else{
					s2.push(input[i]);
					ans.push_back(2);
				}
			}
			else if(s1.top()>s2.top())
			{
				val = func(s1,s2, input[i]);
				if(val==-1)
				{
					break;
				}
				ans.push_back(val);
			}
			else{
				val = func(s2,s1, input[i]);
				if(val==-1)
				{
					break;
				}
				ans.push_back(3-val);
			}
		}
		while(!s1.empty()||!s2.empty())
		{
			if(!s1.empty())
			{
				if(s1.top()==x)
				{
					x++;s1.pop();
					continue;
				}
			}
			if(!s2.empty())
			{
				if(s2.top()==x)
				{
					x++;s2.pop();
					continue;
				}
			}
			break;
		}
	}
	
	if(val==-1 || s1.size()!=0 || s2.size()!=0)
	{
		cout<<"IMPOSSIBLE";
	}
	else 
	for(long long i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}
