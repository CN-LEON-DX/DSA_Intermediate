#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int k; 
        cin >> k;
        pq.push(k);
    }

    int totalSum = 0;
    cout << totalSum << endl;
    while (pq.size() > 1) {
        int s1 = pq.top(); pq.pop();
        int s2 = pq.top(); pq.pop();
        
        totalSum += (s1 + s2); 
        pq.push(s1 + s2);
    }

    cout << totalSum;
    return 0;
}
