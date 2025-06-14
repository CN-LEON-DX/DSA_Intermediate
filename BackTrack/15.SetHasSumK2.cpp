#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x;
vector<int> a, res;
vector<vector<int>> result;

void print() {
    for (auto &v : result) {
        cout << "{";
        for (int i = 0; i < v.size(); i++) {
            if (i==v.size()-1) cout << v[i];
            else cout << v[i] << " ";
        }
        cout << "}" << endl;
    }
}

void Try(int i, int sum) {
    if (sum == x) {
        result.push_back(res);
        return;
    }
    for (int j = i; j < n; j++) {
        if (sum + a[j] <= x) {
            res.push_back(a[j]);
            Try(j, sum + a[j]);
            res.pop_back();
        }
    }
}

int main() {
    cin >> n >> x;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    Try(0, 0);
    if (result.empty()) {
        cout << -1 << endl;
    } else {
        cout << result.size() << endl;
        print();
    }
    return 0;
}