#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;
using vi = vector<int>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()

#define endl "\n"
#define INF 987654321
#define MOD 1'000'000'007

#define MAX_N 1'000'000

int dp[MAX_N + 10];
int before[MAX_N + 10];
int N;

void buildTable() {
    dp[1] = 0;
    before[1] = 0;
    for (int i = 2; i <= MAX_N; i++) {
        int is2 = INF, is3 = INF;

        if (!(i % 2)) is2 = dp[i / 2];
        if (!(i % 3)) is3 = dp[i / 3];

        int minVal = min(min(is2, is3), dp[i - 1]);

        if (minVal == is3) {
            before[i] = i / 3;
        } else if (minVal == is2) {
            before[i] = i / 2;
        } else {
            before[i] = i - 1;
        }

        dp[i] = minVal + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    buildTable();

    cin >> N;

    cout << dp[N] << endl;

    cout << N << " ";
    while (before[N]) {
        cout << (N = before[N]) << " ";
    }

    return 0;
}