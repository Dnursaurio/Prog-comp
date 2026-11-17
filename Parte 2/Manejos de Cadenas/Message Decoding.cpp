#include <bits/stdc++.h>

using namespace std;

char code[8][256];
int rc(){int c; while((c= getchar()) == '\n' || c == '\r'); return c;}
int ri(int n, int v = 0){while(n--) v = v * 2 + rc() - '0'; return v;}

bool readcodes()
{
	if((code[1][0] = rc()) == EOF)  return false;
	for(int l = 2; l <= 7; l++)
	{
		for(int i =0; i <(1 << l) - 1; i++)
		{
			int c = getchar();
			if(c == EOF) return true;
			if(c == '\n' || c == '\r') return true;
			code[l][i] = c;
		}
	}
	return true;
}

int main()
{
	for(int l,v; readcodes();putchar('\n'))
	{
		while((l = ri(3)))
		{
			while((v = ri(l)) != (1 << l) - 1) putchar(code[l][v]);
		}
	}
}
