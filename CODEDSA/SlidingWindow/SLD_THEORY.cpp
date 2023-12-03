#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
    if (n<k){
        cout << 0;
        return;
    }
    fore (i, 0, n) cin >> a[i];
    int index = 0;
    ll sum = accumulate(a, a+k, 0ll);
    ll maxe = sum;
    for (int i = 1;i<=n-k;i++){
        sum-=a[i-1];
        sum+=a[i+k-1];
        if (maxe < sum){
            index = i;
            maxe = sum;
        }
    }
    cout << maxe << endl;
    for (int i = index;i<index + k;i++){
        cout << a[i] << " ";
    }
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t = 1;
    while (t--){
        slove();
    }
}

// Cho dãy số A[] gồm có N phần tử và số nguyên dương k. Hãy tìm dãy con liên tiếp có k phần tử sao cho dãy con đó có tổng các phần tử lớn nhất.

// Input Format

// Dòng đầu tiên là số nguyên N và K. Dòng tiếp theo gồm N số nguyên A[i]

// Constraints

// 1≤ K ≤ N ≤ 10^7; 1 ≤ A[i] ≤ 10^9;

// Output Format

// Dòng 1 in ra tổng lớn nhất của dãy con K phần tử liền kề. Dòng 2 in ra dãy con đó, nếu có nhiều dãy con có cùng tổng lớn nhất thì in ra dãy con xuất hiện đầu tiên.

// Sample Input 0

// 59 4
// 72 39 5 74 29 83 63 67 69 10 50 86 32 66 96 100 47 32 41 96 9 7 58 97 87 26 21 23 100 52 31 76 43 74 17 72 104 40 99 8 16 27 38 78 69 46 16 58 73 52 49 67 62 42 64 28 46 34 83 
// Sample Output 0

// 315
// 72 104 40 99