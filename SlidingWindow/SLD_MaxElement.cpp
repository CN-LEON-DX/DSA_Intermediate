#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fore(i,b,a) for(int i = b; i<a; i++)
#define null NULL
#define nl '\n'
#define yes "YES\n"
#define no "NO\n"
using namespace std;

void slove(){
    int n, k; cin >> n >> k;
    int a[n];
    fore(i, 0, n) cin >> a[i];
    
    if (k == 1 && n != 1) {
        for (int i = 0; i < n; i++) 
            cout << a[i] << " ";
        return;
    } else if (n == 1) {
        cout << a[0];
        return;
    }
    
    if (n < k) {
        cout << *min_element(a, a + n) << " " << *max_element(a, a + n);
        return;
    }
    
    multiset<int> ms;
    int left = 0;
    for (int i = 0; i < k; i++) {
        ms.insert(a[i]);
    }
    
    cout << *ms.begin() << " " << *ms.rbegin() << endl;
    
    for (int i = 1; i + k - 1 < n; i++) {
        auto it = ms.find(a[left]);
        ms.erase(it);
        left++;
        ms.insert(a[i + k - 1]);
        cout << *ms.begin() << " " << *ms.rbegin() << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    ll t;
    t = 1;
    while (t--) {
        slove();
    }

    return 0;
}

// Cho mảng A[] gồm N phần tử và số nguyên K, nhiệm vụ của bạn là in ra số lớn nhất và nhỏ nhất của mọi mảng con cỡ K của mảng A[]

// Input Format

// Dòng đầu tiên là N và K; Dòng thứ 2 gồm N phần tử A[i]

// Constraints

// 1<=K<=N<=10^6; 0<=A[i]<=10^9

// Output Format

// In ra số lớn nhất và nhỏ nhất của mọi mảng con trên từng dòng.

// Sample Input 0

// 8 2
// 8 5 8 6 7 6 5 8 
// Sample Output 0

// 5 8
// 5 8
// 6 8
// 6 7
// 6 7
// 5 6
// 5 8