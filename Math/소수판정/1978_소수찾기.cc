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

#define MAX_N 1'000'000

vector<bool> isPrime(MAX_N + 10, true);

int M, N;

void fillPrimeVector() {
    isPrime[1] = false;

    for (int i = 2; i <= 1'000; i++) {
        if (!isPrime[i]) continue;

        for (int j = i * 2; j <= MAX_N; j += i) {
            isPrime[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fillPrimeVector();

    cin >> N;

    int res = 0;
    while (N--) {
        int x;
        cin >> x;

        (isPrime[x]) ? (res++) : res;
    }

    cout << res << "\n";

    return 0;
}