#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Edge
{
	int u,v,ppa;
};
vector<Edge> edges;
vector<int>parent_node,sz;

int find_root(int i)
{
	return parent_node[i] == i ? i: parent_node[i] = find_root(parent_node[i]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m;
	while(cin>>n>>m && (n || m))
	{
		edges.resize(m);
		int max_ppa = -2e9;
		for(int i = 0; i < m; i++)
		{
			cin>>edges[i].u>>edges[i].v>>edges[i].ppa;
			if(edges[i].ppa > max_ppa) max_ppa = edges[i].ppa;
		}
		parent_node.resize(n + 1);
		sz.assign(n + 1,1);
		for(int i = 1; i <= n; i++) parent_node[i] = i;
		int max_cities = 1;
		for(const auto& e: edges)
		{
			if(e.ppa == max_ppa)
			{
				int ru = find_root(e.u), rv = find_root(e.v);
				if(ru != rv)
				{
					parent_node[rv] = ru;
					sz[ru] += sz[rv];
					if(sz[ru] > max_cities) max_cities = sz[ru];
				}
			}
		}
		cout<<max_cities<<"\n";
	}
	return 0;
}
