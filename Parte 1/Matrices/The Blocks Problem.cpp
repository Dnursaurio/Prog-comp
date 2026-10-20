#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int n;
vector<vector<int>> p;
void find_block(int b, int& pos, int& h){
	for(int i=0; i<n; ++i)
		for(int j=0; j<p[i].size(); ++j)
		if(p[i][j] == b){ pos = i; h = j; return; }
}
	void clear_above(int pos, int h){
		while(p[pos].size() > h + 1){
			int b = p[pos].back();
			p[pos].pop_back();
			p[b].push_back(b);
		}
	}
		int main(){
			ios_base::sync_with_stdio(0); cin.tie(0);
			if(!(cin >> n)) return 0;
			p.resize(n);
			for(int i=0; i<n; ++i) p[i] = {i};
			string s1, s2;
			int a, b;
			while(cin >> s1 && s1 != "quit"){
				cin >> a >> s2 >> b;
				int pa, ha, pb, hb;
				find_block(a, pa, ha);
				find_block(b, pb, hb);
				if(pa == pb || a == b) continue;
				if(s1 == "move"){
					if(s2 == "onto"){
						clear_above(pa, ha);
						clear_above(pb, hb);
						p[pa].pop_back();
						p[pb].push_back(a);
					} else { // over
						clear_above(pa, ha);
						p[pa].pop_back();
						p[pb].push_back(a);
					}
				} else { // pile
					if(s2 == "onto"){
						clear_above(pb, hb);
						vector<int> moving(p[pa].begin() + ha, p[pa].end());
						p[pa].erase(p[pa].begin() + ha, p[pa].end());
						p[pb].insert(p[pb].end(), moving.begin(), moving.end());
					} else { // over
						vector<int> moving(p[pa].begin() + ha, p[pa].end());
						p[pa].erase(p[pa].begin() + ha, p[pa].end());
						p[pb].insert(p[pb].end(), moving.begin(), moving.end());
					}
				}
			}
			for(int i=0; i<n; ++i){
				cout << i << ":";
				for(int x : p[i]) cout << " " << x;
				cout << "\n";
			}
		}
