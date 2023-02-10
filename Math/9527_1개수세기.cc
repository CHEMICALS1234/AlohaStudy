#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;
using vi = vector<int>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()

#define endl "\n"
#define INF 2e18
#define MOD 1'000'000'007

#define MAX 55

ll dp[MAX];  // dp[i]: MSB가 i번째 bit 일때의 1 개수 누적합.
ll A, B;

void buildTable() {
    dp[0] = 1;

    for (int i = 1; i < MAX; i++) {
        dp[i] = 2 * dp[i - 1] + (1LL << i);
    }
}

ll getSum(ll x) {
    ll ans = x & 1;  // 걍 홀짝 check.

    for (int i = MAX - 1; i > 0; i--) {
        if (x & (1LL << i)) {
            ans += dp[i - 1] + (x - (1LL << i) + 1);
            x -= (1LL << i);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    buildTable();

    cin >> A >> B;

    cout << getSum(B) - getSum(A - 1) << endl;

    return 0;
}