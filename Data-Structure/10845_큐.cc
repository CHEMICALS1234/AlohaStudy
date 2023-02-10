#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    while (N--) {
        string instr;
        cin >> instr;

        if (instr == "push") {
            int X;
            cin >> X;
            q.push(X);
        } else if (instr == "pop") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (instr == "size") {
            cout << q.size() << "\n";
        } else if (instr == "empty") {
            cout << q.empty() << "\n";
        } else if (instr == "front") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
            }
        } else if (instr == "back") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.back() << "\n";
            }
        }
    }

    return 0;
}