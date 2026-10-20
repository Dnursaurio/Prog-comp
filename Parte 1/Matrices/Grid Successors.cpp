#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef vector<string> G;

G f(const G& g){
	G r(3,"000");
	int dr[]={-1,1,0,0}, dc[]={0,0,-1,1};
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j){
		int s=0;
		for(int k=0; k<4; ++k){
			int nr=i+dr[k], nc=j+dc[k];
			if(nr>=0 && nr<3 && nc>=0 && nc<3) s += g[nr][nc]-'0';
		}
		r[i][j] = (s % 2) + '0';
	}
		return r;
}
	
	int main(){
		ios_base::sync_with_stdio(0); cin.tie(0);
		int t; 
		if(!(cin >> t)) return 0;
		while(t--){
			G g(3);
			cin >> g[0] >> g[1] >> g[2];
			vector<G> q;
			G curr = g;
			int cycle_start = -1;
			
			while(true){
				int found = -1;
				for(size_t i = 0; i < q.size(); ++i){
					if(q[i] == curr){ found = i; break; }
				}
				if(found != -1){
					cycle_start = found;
					break;
				}
				q.push_back(curr);
				curr = f(curr);
			}
			
			if(cycle_start == 0){
				cout << -1 << "\n";
			} else {
				cout << cycle_start - 1 << "\n";
			}
		}
	}
