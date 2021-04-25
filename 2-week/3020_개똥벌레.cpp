#include <iostream>
#include <algorithm>

using namespace std;

int N, h;
int n;

void howmany(int obstacle_under[], int obstacle_above[])
{
  int ans = 200000, temp_ans = 0, cnt = 1;
  for (int i = 1; i <= h; i++)
  {
    // temp_ans = 0;
    temp_ans = n - (lower_bound(obstacle_under, obstacle_under + n, i) - obstacle_under);
    temp_ans += n - (upper_bound(obstacle_above, obstacle_above + n, h - i) - obstacle_above);
    if (temp_ans <= ans)
    {
      if (temp_ans == ans)
      {
        cnt++;
      }
      else if (temp_ans < ans)
      {
        cnt = 1;
      }
      ans = temp_ans;
    }
  }
  cout << ans << " " << cnt << "\n";
}

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> h;
  n = N / 2;
  int obstacle_under[n];
  int obstacle_above[n];
  for (int i = 0; i < n; i++)
  {
    cin >> obstacle_under[i];
    cin >> obstacle_above[i];
  }
  sort(obstacle_under, obstacle_under + n);
  sort(obstacle_above, obstacle_above + n);
  howmany(obstacle_under, obstacle_above);
  return 0;
}