#include<bits/stdc++.h>
using namespace std;


set<string> solve(string s)
{
    sort(s.begin(), s.end());

    set<string> us;

    do {
        us.insert(s);
    } while (next_permutation(s.begin(), s.end()));
    return us;
}

int main()
{
	string s;
	cin>>s;
	
	set<string> ans = solve(s);
	
	cout<<ans.size()<<"\n";
	for(auto it:ans)
	{
		cout<<it<<"\n";
	}
	
}
