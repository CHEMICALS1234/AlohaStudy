#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void printSubset(const vector<T>& v) {
	int n = v.size();
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if ((i & (1 << j)) != 0) {
				cout << v[j] << " ";
			}
		}
		cout << "\n";
	}
}

int main() {
	vector<string> u = {"a","b","c","d"};

	printSubset(u);
		
	return 0;
}
