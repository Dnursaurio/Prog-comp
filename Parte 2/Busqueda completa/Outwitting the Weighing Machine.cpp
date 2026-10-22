#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int T;
	if(!(cin>>T))return 0;
	vector<vector<int>> test_cases(T,vector<int>(10));
	for(int t = 0; t < T; t++)
	{
		for(int i = 0; i < 10; i++)
		{
			cin>>test_cases[t][i];
		}
	}
	
	for(int t = 0; t < T; t++)
	{
		const auto& w = test_cases[t];
		int sz_sum = 0;
		for(int x : w) sz_sum += x;
		int sum = sz_sum / 4;
	 	
		int x0 = (w[0] + w[1] - w[3]) / 2;
		int x1 = w[0] - x0;
		int x2 = w[1] - x0;
		int x4 = (w[9] + w[8] - w[4]) / 2;
		int x3 = sum - (x0 + x1 + x2 + x4);
		int ans_arr[5] = {x0,x1,x2,x3,x4};
		sort(ans_arr,ans_arr + 5);
		cout<< "Case "<< (t + 1)<<":";
		for(int i = 0; i < 5; i++)
		{
			cout<<" "<<ans_arr[i];
		}
		cout<<"\n";
	}
	return 0;
}
