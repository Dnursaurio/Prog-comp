#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> m;
int id = 1;

void f(string s, char n, int l)
{
	if(s.size() == l)
	{
		m[s] = id++;
		return;
	}
	for(char c = n; c<= 'z'; c++)
	{
		f(s + c, c + 1, l);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	unordered_map<string,int>mp;
	int idx = 1;
	
	for(int len = 1; len <= 5; len++)
	{
		f("",'a',len);
	}

	vector<string>inputs;
	string s;
	while(cin>>s)
	{
		inputs.push_back(s);
	}
	for(auto& word: inputs)
	{
		cout<<m[word]<<"\n";
	}
	return 0;
}
