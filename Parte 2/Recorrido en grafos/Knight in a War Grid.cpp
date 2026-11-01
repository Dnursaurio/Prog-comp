#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int T,R,C,M,N,W;
int grid[105][105];
int visited[105][105];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int cas=1;cin>>T;
	while(T--){
		cin>>R>>C>>M>>N>>W;
		while(W--){
			int x,y;cin>>x>>y;
			grid[x][y]=-1;
		}
		
		int dx[]={N,N,-N,-N,M,M,-M,-M};
		int dy[]={M,-M,M,-M,N,-N,N,-N};
		int odd=0, even=0;
		
		queue<int>q;
		q.push(0);q.push(0);
		
		while(!q.empty()){
			int x=q.front();q.pop();
			int y=q.front();q.pop();
			int temp = 0;
			if(visited[x][y]==1)continue;
			visited[x][y]=1;
			
			set<pii>used;
			for(int i = 0;i<8;i++){
				if(x+dx[i]<0 || x+dx[i]>=R)continue;
				if(y+dy[i]<0 || y+dy[i]>=C)continue;
				if(grid[x+dx[i]][y+dy[i]]==-1)continue;
				
				pii tc = pii(x+dx[i],y+dy[i]);
				if(used.count(tc)==1)continue;
				used.insert(tc);
				if(visited[x+dx[i]][y+dy[i]]!=1){q.push(x+dx[i]);q.push(y+dy[i]);}
				temp++;
			}
			grid[x][y]=temp;
			if(temp%2==0)even++;
			else odd++;
		}
		
		/*for(int i = 0;i<R;i++){
		for (int j = 0;j<C;j++){
		cout<<grid[i][j]<<' ';
		}
		cout<<endl;
		}*/
		cout<<"Case "<<cas++<<": "<<even<<' '<<odd<<'\n';
		memset(grid,0,sizeof(grid));
		memset(visited,0,sizeof(visited));
	}
}
