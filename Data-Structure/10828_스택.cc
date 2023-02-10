#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N;
stack<int> s;

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
            s.push(X);
        } else if (instr == "pop") {
            if (s.empty()) {
                cout << -1 << "\n";
            } else {
                cout << s.top() << "\n";
                s.pop();
            }
        } else if (instr == "size") {
            cout << s.size() << "\n";
        } else if (instr == "empty") {
            cout << s.empty() << "\n";
        } else {
            if (s.empty()) {
                cout << -1 << "\n";
            } else {
                cout << s.top() << "\n";
            }
        }
    }

    return 0;
}