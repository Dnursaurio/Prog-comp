#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(long long k, const vector<long long>& r)
{
	for(size_t i = 0; i < r.size(); i++)
	{
		long long diff = (i == 0) ? r[0] : r[i] - r[i - 1];
		if(diff > k) return 0;
		if (diff == k) k--;
	}
	return 1;
}

void solve(int case_num)
{
	int n;
	if(!(cin>>n)) return;
	vector<long long> r(n);
	long long max_diff = 0;
	long long prev = 0;
	for(int i = 0; i < n ; i++)
	{
		cin>> r[i];
		long long diff = r[i] - prev;
		if(diff > max_diff) max_diff = diff;
		prev = r[i];
	}
	
	long long low = max_diff, high = r[n - 1], ans = high;
	while(low <= high)
	{
		long long mid = low + (high - low) / 2;
		if(possible(mid,r))
		{
			ans = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	cout<<"Case "<<case_num<<": "<<ans<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	if(cin>>t)
	{
		for(int i = 1; i <= t ; i++)
		{
			solve(i);
		}
	}
	return 0;
}
