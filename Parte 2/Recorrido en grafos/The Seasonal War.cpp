#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(int r, int c, int n, vector<string> &grid, vector<vector<bool>>& vis)
{
	if(r<0 || r >= n || c < 0 || c >= n || vis[r][c] || grid[r][c] == '0') return;
	vis[r][c]=true;
	int dr[] = {-1,-1,-1,0,0,1,1,1};
	int dc[] = {-1,0,1,-1,1,-1,0,1};
	for(int i = 0; i < 8; i++)
	{
		dfs(r + dr[i], c + dc[i],n,grid,vis);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	vector<vector<string>> all_images;
	vector<int> dimensions;
	while(cin>>n)
	{
		dimensions.push_back(n);
		vector<string> grid(n);
		for(int i = 0; i < n; i++)
		{
			cin>>grid[i];
		}
		all_images.push_back(grid);
	}
	
	for(size_t k = 0; k < all_images.size(); k++)
	{
		int n = dimensions[k];
		vector<string>&grid = all_images[k];
		vector<vector<bool>> vis(n,vector<bool>(n,false));
		int count = 0;
		for(int i = 0; i < n;i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(grid[i][j] == '1' && !vis[i][j])
				{
					dfs(i,j,n,grid,vis);
					count++;
				}
			}
		}
		cout<<"Image number "<<k + 1<<" contains " << count << " war eagles.\n"; 
	}
	return 0;
}
