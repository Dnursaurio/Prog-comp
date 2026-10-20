#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	if(!(cin>>n)) return 0;
	string dummy;
	getline(cin,dummy);
	while(n--)
	{
		string s;
		getline(cin,s);
		stack<char>st;
		bool ok = true;
		for(char c : s)
		{
			if(c == '(' || c == '[')
			{
				st.push(c);
			}
			else if(c == ')')
			{
				if(st.empty() || st.top() != '(') {ok = false; break;}
				st.pop();
			}
			else if(c == ']')
			{
				if(st.empty() || st.top() != '['){ ok = false; break;}
				st.pop();
			}
		}
		if(!st.empty()) ok = false;
		cout<<(ok?"Yes":"No")<<"\n";
	}
	return 0;
}
