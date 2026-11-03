#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	bool adj[26][26] = {},used[26] = {};
	int ref[26] = {};
	char s1[21],s2[21];
	
	if(!gets(s1))return 0;
	
	while(gets(s2) && s2[0] != '#')
	{
		int i = 0;
		while(s1[i] && s1[i] == s2[i]) i++;
		if(s1[i] && s2[i]) adj[s1[i] - 'A'][s2[i] - 'A'] = true;
		for(int k = 0; k < 21; k++) s1[k] = s2[k];
	}
	
	queue<int>Q;
	for(int i = 0; i < 26; i++)
	{
		for(int j = 0; j < 26; j++)
		{
			if(adj[i][j]) used[i] = used[j] = true, ref[j]++;
		}
	}
	
	for(int i = 0; i < 26; i++)
	{
		if(used[i] && !ref[i]){Q.push(i); break;}
	}
	
	if(Q.empty()) putchar(s1[0]);
	
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		putchar('A' + u);
		for(int i = 0; i < 26; i++)
		{
			if(used[i] && adj[u][i] && --ref[i] == 0) Q.push(i); 
		}
	}
	putchar('\n');
}
