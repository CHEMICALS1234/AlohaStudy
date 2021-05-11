#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> LIS;
  int v[n];
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++)
  {
    int bound = lower_bound(LIS.begin(), LIS.end(), v[i]) - LIS.begin();
    if (bound != LIS.size())
    {
      LIS[bound] = v[i];
    }
    else
    {
      LIS.push_back(v[i]);
    }
  }
  cout << LIS.size() << "\n";

  return 0;
}