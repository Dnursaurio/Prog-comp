#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	string s;
	int t = 1;
	while(cin>>s && s != "end")
	{
		vector<char> v;
		for(char c : s)
		{
			auto it = lower_bound(v.begin(),v.end(),c);
			if(it == v.end()) v.push_back(c);
			else *it = c;
		}
		cout<<"Case "<<t++<<": "<<v.size()<<"\n";
	}
	return 0;
}
