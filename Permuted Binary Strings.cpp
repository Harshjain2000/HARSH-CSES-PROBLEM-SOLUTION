#include<bits/stdc++.h>
using namespace std;

vector<vector<long long> >helper;
string val;

string query(string &s)
{
	cout<<"? "<<s<<endl;
	cin>>val;
	
	return val;
}



class CustomComparator {
private:
    string param; 

public:
    explicit CustomComparator(string p) : param(p) {}

    bool operator()(long long  i, long long j) const {
        return  param[i] > param[j];
    }
};


string buildq(vector<long long > &t)
{
	string res = "";
	for(long long i=0;i<helper.size();i++)
	{
		long long mid = (helper[i].size()/2);
		for(long long k=0;k<helper[i].size();k++)
		{
			if(k<mid)
			res.push_back('1');
			
			else{
				res.push_back('0');
			}
		}
	}
	
	return res;
}


void printhelper(string &b)
{
	cout<<"start========= "<<endl;
	cout<<"res:"<<b<<endl;
	
	for(long long i=0;i<helper.size();i++)
	{
		cout<<"-----";
		for(long long j=0;j<helper[i].size();j++)
		cout<<helper[i][j]<<" ";
		
		cout<<endl<<"-----";
	}
	cout<<"end========="<<endl;
}

void update(string &res)
{
	//printhelper(res);
	vector<vector<long long > > nhelper;
	
	for(long long i=0;i<helper.size();i++)
	{
		long long mid = helper[i].size()/2;
		vector<long long >a,b;
		for(long long j=0;j<helper[i].size();j++)
		{
			if(res[helper[i][j]]=='1')
			{
				a.push_back(helper[i][j]);
			}
			else{
				b.push_back(helper[i][j]);
			}
		}
		if(a.size()!=0)
		nhelper.push_back(a);
		
		if(b.size()!=0)
		nhelper.push_back(b);
	}
	
	helper = nhelper;
	
//	printhelper(res);
}


int main()
{
	long long n,count=0;
	cin>>n;
	
	vector<long long > tmp(n),ans(n);
	
	
	for(long long i=0;i<n;i++)
	{
		tmp[i] = i;
	}
	
	helper.clear();	
	helper.push_back(tmp);
	
	while(1)
	{
		
		string askq = buildq(ans);
		string res = query(askq);
		
		update(res);
		count=0;
		for(long long i=0;i<helper.size();i++)
		{
			if(helper[i].size()==1)
			{
				count++;
			}	
		}		
		if(count==n)
		{
			break;
		}
	}
	
	for(long long i=0;i<helper.size();i++)
	{
		ans[helper[i][0]] = i+1;
	}
	
	cout<<"! ";
	
	for(long long i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
