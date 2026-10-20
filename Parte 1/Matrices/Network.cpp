#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> adj;
vector<int> depth, parent_node;
vector<pair<int, int>> nodes;

void dfs(int u, int p, int d) {
	depth[u] = d;
	parent_node[u] = p;
	nodes.push_back({d, u});
	for(int v : adj[u]) {
		if(v != p) dfs(v, u, d + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; if(!(cin >> t)) return 0;
	while(t--){
		int n; cin >> n;
		int s, k; cin >> s >> k;
		adj.assign(n + 1, vector<int>());
		for(int i = 0; i < n - 1; ++i){
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		depth.assign(n + 1, 0);
		parent_node.assign(n + 1, 0);
		nodes.clear();
		dfs(s, 0, 0);
		
		sort(nodes.rbegin(), nodes.rend());
		vector<bool> covered(n + 1, false), has_replica(n + 1, false);
		int replicas = 0;
		
		for(auto& p : nodes) {
			int u = p.second;
			if(adj[u].size() == 1 && u != s) { // terminal node / client
				if(depth[u] > k && !covered[u]) {
					int curr = u;
					for(int step = 0; step < k; ++step) curr = parent_node[curr];
					has_replica[curr] = true;
					replicas++;
					
					vector<pair<int, int>> q = {{curr, 0}};
					vector<bool> visited(n + 1, false);
					visited[curr] = true;
					int head = 0;
					while(head < (int)q.size()){
						int cnode = q[head].first;
						int dist = q[head].second;
						head++;
						if(adj[cnode].size() == 1) covered[cnode] = true;
						if(dist < k) {
							for(int nxt : adj[cnode]){
								if(!visited[nxt]){
									visited[nxt] = true;
									q.push_back({nxt, dist + 1});
								}
							}
						}
					}
				}
			}
		}
		// check initial coverage for original server
		vector<pair<int, int>> q = {{s, 0}};
		vector<bool> visited(n + 1, false);
		visited[s] = true;
		int head = 0;
		while(head < (int)q.size()){
			int cnode = q[head].first;
			int dist = q[head].second;
			head++;
			if(adj[cnode].size() == 1) covered[cnode] = true;
			if(dist < k) {
				for(int nxt : adj[cnode]){
					if(!visited[nxt]){
						visited[nxt] = true;
						q.push_back({nxt, dist + 1});
					}
				}
			}
		}
		
		cout << replicas << "\n";
	}
}
