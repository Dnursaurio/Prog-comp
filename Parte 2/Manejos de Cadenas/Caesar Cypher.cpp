#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s,cipher; set<string> d;
	while(cin>>s && s != "#") d.insert(s);
	cin.ignore();
	while(getline(cin,cipher))
	{
		string b = ""; int m = -1;
		for(int k = 0; k < 27; k++)
		{
			string dec = "";
			for(char c: cipher) dec += (c == ' ')? ' ' : ((c - 'A'- k + 27) % 27 ? 'A' + (c - 'A' - k + 27) % 27 : ' ');
			stringstream ss(dec); string w; int cur = 0;
			while(cin>>w) if(d.count(w)) cur++;
			if(cur > m){m = cur; b = dec;}
		}
		stringstream ss(b); string w, l = "";
		while(ss>>w)
		{
			if(l.length() + w.length() + !l.empty() > 60){cout<<l<<'\n'; l = w;}
			else l += (l.empty() ? "" : " ") + w;
		}
		cout<<l<<'\n';
	}
}
