#include<bits/stdc++.h>
using namespace std;
int N,n,m,k,u,v,w,s,d,c;
vector<pair<int,int>> a[55];
bool gp(int s,int d,vector<int>&p){
	vector<int> par(n+1,-1),pw(n+1);vector<bool> vis(n+1);queue<int> q;q.push(s);vis[s]=1;
	while(!q.empty()){int u=q.front();q.pop();for(auto& e:a[u])if(!vis[e.first])vis[e.first]=1,par[e.first]=u,pw[e.first]=e.second,q.push(e.first);}
	if(!vis[d]||s==d)return 0;
	p.clear();for(int x=d;x!=s;x=par[x])p.push_back(pw[x]);
	reverse(p.begin(),p.end());return 1;
}
	int main(){
		ios::sync_with_stdio(0);cin.tie(0);
		if(cin>>N)for(int t=0;t<N;t++){
			if(t)cout<<"\n";cin>>n>>m;
			for(int i=1;i<=n;i++)a[i].clear();
			while(m--)cin>>u>>v>>w,a[u].push_back({v,w}),a[v].push_back({u,w});
			cin>>k;while(k--){
				cin>>s>>d>>c;vector<int> p;
				if(!gp(s,d,p)){cout<<"No\n";continue;}
				long long b=0;for(int x:p)b+=x;
				if(c<b||(c-b)%2){cout<<"No\n";continue;}
				int T=(c-b)/2;if(!T){cout<<"Yes "<<p.size()<<"\n";continue;}
				vector<int> coins(p.begin(),p.end()-1);sort(coins.begin(),coins.end());
				coins.erase(unique(coins.begin(),coins.end()),coins.end());
				vector<int> dp(T+1,1e9);dp[0]=0;
				for(int i=1;i<=T;i++)for(int x:coins)if(x<=i)dp[i]=min(dp[i],dp[i-x]+1);
				if(dp[T]>=1e9)cout<<"No\n";else cout<<"Yes "<<p.size()+2*dp[T]<<"\n";
			}
		}
	}
