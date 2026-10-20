#include <iostream>
#include <string>
#include <stack>

using namespace std;

string line;
int p(char c)
{
	return (c == '*' || c == '/')? 2:(c == '+' || c == '-');
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	if(!(cin>>t)) return 0;
	string s;
	getline(cin,s);
	getline(cin,s);
	for(int i = 0; i < t; i++)
	{
		
		string expr = "", line;
		while(getline(cin,line) && !line.empty() && line != "\r")
		{
			expr += line[0];
		}
		string post = "";
		stack<char> st;
		for(char c : expr)
		{
			if(isdigit(c)) post +=c;
			else if(c == '(') st.push(c);
			else if(c == ')')
			{
				while(!st.empty() && st.top() != '(')
				{
					post += st.top();
					st.pop();
				}
				if(!st.empty()) st.pop();
			}
			else
			{
				while(!st.empty() && st.top() != '(' && p(st.top()) >= p(c))
				{
					post += st.top();
					st.pop();
				}
				st.push(c);
			}
		}
		while(!st.empty())
		{
			if(st.top() != '(') post += st.top();
			st.pop();
		}
		if(i>0)cout<<"\n";
		cout<<post<<"\n";
	}
	return 0;
}
