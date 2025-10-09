#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;
vector<long long> dp;

class trie{
	
	
	public:
	vector<trie *> node;
	bool end ;
	void inserttrie(string &x);
	
	trie()
	{
		node.clear();
		node.resize(26, NULL);
		end= false;
	}
};

void trie:: inserttrie(string &x)
{
	trie *tmp  = this;
	
	for(long long i=0;i<x.size();i++)
	{
		if(tmp->node[x[i]-'a']==NULL)
		{
			tmp->node[x[i]-'a'] = new trie();
		}
		tmp = tmp->node[x[i]-'a'];
		
		if(x.size() == (i+1))
		tmp->end = true;
	}
	
}


long long check(string &s , trie *root, long long e)
{
	if(e == s.size())
	{
		return 1;
	}
	if(dp[e]!=-1)
	{
		return dp[e];	
	}
	trie * tmp = root;
	long long count = 0;
	for(long long i=e;i<s.size();i++)
	{
		if(tmp!=NULL && tmp->node[s[i]-'a']!=NULL)
		{
			tmp = tmp->node[s[i]-'a'];
		}
		else{
			break;
		}
		if(tmp->end)
		{
			count += check(s, root, i+1);
		}
		count = count%mod;
	}
	dp[e] = count;
	//cout<<e<<" "<<s<<" "<<count<<" "<<depth<<"\n";
	return count;
}

void printer(trie * root, long long depth)
{
	if(root==NULL)
	{
		cout<<"NULL\n";
		return ;
	}
	for(long long i=0;i<26;i++)
	{
		if(root->node[i]!=NULL){
			cout<<"start  ";
			cout<<(char)(i+'a')<<" "<<root->node[i]<<" "<<root->node[i]->end<<" "<<depth;
			cout<<" end\n";
			printer(root->node[i], depth+1);
		}
	}

}

int main()
{
	string s,x;
	cin>>s;
	
	long long n,mod = 1e9+7;
	cin>>n;
	
	dp.clear();
	dp.resize(s.size(),-1);
	
	trie *root= new trie();
	
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		root->inserttrie(x);
	}
	//printer(root, 1);
	cout<<check(s, root, 0);
	
	
	return 0;
}
