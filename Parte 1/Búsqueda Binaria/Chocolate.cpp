#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int T;
	cin>>T;
	int count = 0;
	while(T--)
	{
		count++;
		int l,r,s,x;
		cin>>l>>r>>s;
		bool tiene[3][100001]={};
		for(int i = 0; i < l; i++)
		{
			cin>>x;
			tiene[0][x] = true;
		}
		for(int i = 0; i < r; i++)
		{
			cin>>x;
			tiene[1][x] = true;
		}
		for(int i = 0; i < s; i++)
		{
			cin>>x;
			tiene[2][x] = true;
		}
		int a1=0,a2=0,b1=0,b2=0,c1=0,c2=0;
		for(int i = 0; i < 100001; i++)
		{
			bool l = tiene[0][i], r = tiene[1][i], s = tiene[2][i];
			if(l && !r  && !s) a1++;
			if(!l && r && s) a2++;
			if(!l && r && !s) b1++;
			if(l && !r && s) b2++;
			if(!l && !r && s) c1++;
			if(l && r && !s) c2++;
		}
		cout<<"Case #"<<count<<":"<<endl;
		cout<<a1<<" "<<a2<<endl;
		cout<<b1<<" "<<b2<<endl;
		cout<<c1<<" "<<c2<<endl;
	}
	return 0;
}
