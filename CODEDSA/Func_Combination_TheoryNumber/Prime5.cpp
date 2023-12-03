// Theo Goldbach conjecture, một số nguyên dương chẵn >=4 đều có thể biểu diễn dưới dạng tổng của 2 số nguyên tố. Cho số nguyên dương chẵn N >=4 . Hãy liệt kê các cặp số nguyên tố p, q có tổng đúng bằng N. Ví dụ N = 6 ta có 1 cặp số nguyên tố là 3 + 3 = 6.

// Input Format

// Dòng đầu tiên đưa vào số lượng bộ test T. Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số chẵn N.

// Constraints

// 1≤T≤1000; 4≤N≤1000000

// Output Format

// Đưa ra kết quả mỗi test theo từng dòng, mỗi dòng là một cặp số thỏa mãn. Chú ý mỗi cặp chỉ liệt kê một lần, không xét đến thứ tự.

// Sample Input 0

// 1
// 10
// Sample Output 0

// 3 7
// 5 5
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

int a[10000000];
void sang(){
    for (int i = 0;i<=10000000;i++) a[i] = 1;
    a[0] = 0;
    a[1] = 0;
    for (int i = 2;i<=sqrt(10000000);i++){
        if (a[i])
        for (int j = i * i;j<=10000000;j+=i){
            a[j] = 0;
        }
    }
}
void solve(){
    int n; cin >> n;
    sang();
    while (n--){
        int k; cin >> k;
        for (int i = 2;i<=k/2;i++){
            if (a[i] && a[k-i]){
                cout << i << " " << k - i << endl;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t = 1;
    while (t--){
        solve();
    }
}