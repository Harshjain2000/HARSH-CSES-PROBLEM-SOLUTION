#include<bits/stdc++.h>
using namespace std;

class trie{
	vector<trie*> v;
	
	public:
	trie()
	{
		v.clear();
		v.resize(2,NULL);
	}
	
	long long addxor(long long x)
	{
		trie * tmp = this,*resulttmp2 = this;
		long long p2 = (1ll<<40),y,result= 0;
		
		while(p2>=1)
		{
			y = (x/p2)%2;
		//	cout<<x<<" "<<y<<" "<<p2<<"\n";
			if(tmp->v[y] == NULL)
			{
				tmp->v[y] = new trie();
			}
			if(resulttmp2->v[!y] != NULL)
			{
				result = result*2+1;
				resulttmp2 = resulttmp2->v[!y];
			}
			else{
				result = result*2+0;
				resulttmp2 = resulttmp2->v[y];
			}
			tmp = tmp->v[y];
			p2 /= 2;
		}
	//	cout<<x<<" "<<result<<"\n";
		return result;	
	}
};

void input(long long &n,vector<long long >&v)
{
	cin>>n;
	v.clear();
	v.resize(n);
	
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];
	}
	
	return ;
}

long long solve(long long &n,vector<long long>&v)
{
	long long prefix = 0,ans = 0;
	trie * root = new trie();
	root->addxor(0);
	for(long long i=0;i<n;i++)
	{
		prefix = prefix ^ v[i];
		ans = max(ans, root->addxor(prefix));
	}
	
	return ans;
}

int main()
{
	long long n;
	vector<long long>v;
	
	input(n,v);
	
	cout<<solve(n,v);
	return 0;
}
