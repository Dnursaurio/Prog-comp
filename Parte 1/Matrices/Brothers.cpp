#include<iostream>
#include<vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,r,c,k;
	while(cin>>n>>r>>c>>k && (n||r||c||k)){
		vector<vector<int>> g(r,vector<int>(c));
		for(int i=0;i<r;++i)for(int j=0;j<c;++j)cin>>g[i][j];
		int dr[]={-1,1,0,0},dc[]={0,0,-1,1};
		while(k--){
			vector<vector<int>> ng=g;
			for(int i=0;i<r;++i)for(int j=0;j<c;++j)
				for(int d=0;d<4;++d){
				int ni=i+dr[d],nj=j+dc[d];
				if(ni>=0&&ni<r&&nj>=0&&nj<c&&g[ni][nj]==(g[i][j]+1)%n)
					ng[ni][nj]=g[i][j];
			}
				g=ng;
		}
		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j)cout<<g[i][j]<<(j==c-1?"":" ");
			cout<<"\n";
		}
	}
}
