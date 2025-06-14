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

// Cách tiếp cận Naive: Vẫn bị timelimit tới tận trên 2s và có test lên 1.38s
void slove(){
    int n, k; cin >> n >> k;
    int a[n];
    fore (i, 0, n) cin >> a[i];
    multiset<int> ms;
    for (int i=0;i<k;i++){
        ms.insert(a[i]);
    }
    auto it = next(ms.begin(), k/2);
    if (k%2==0){
        it--;
    }
    cout << *it << " ";
    for (int i = 1;i<n;i++){
        if (i+k<=n){
            ms.insert(a[i+k-1]);
            auto it = ms.find(a[i-1]);
            ms.erase(it);
            auto it1 = next(ms.begin(), k/2);
            if (k%2==0){
                it1--;
            }
            cout << *it1 << " ";
        }
    }
}

// Xử dụng cách tiếp cận Sliding Window: Đã AC
// Với độ phức tạp O(nlogk)
// cần xử lý các giá trị vào ra khỏi cửa sổ trượt
// Nếu giá trị vào là nhỏ hơn giá trị trung vị thì cần tăng giá trị trung vị lên 1 đơn vị
void slove(){
    int n, k; cin >> n >> k;
    int a[n+1];
    fore (i, 1, n+1) cin >> a[i];
    multiset<int> ms;
    for (int i=1;i<=k;i++){
        ms.insert(a[i]);
    }
    auto it = next(ms.begin(), (k-1)/2); //Bao quát cả trường hợp lẻ và chẵn 
    for (int i = k + 1;i<=n+1;i++){
        cout << *it << " ";
        ms.insert(a[i]);
        if (a[i] < *it && it != ms.begin()){
            --it;
        }
        if (a[i - k]<=*it){
            it++;
        }
        ms.erase(ms.lower_bound(a[i-k]));
    }
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t=1;
    while (t--){
        slove();
    }
}

// Cho mảng A[] gồm N phần tử và số nguyên K, bạn hãy tìm median của mọi dãy con liên tiếp cỡ K của mảng A[].

// Input Format

// Dòng 1 là N và K

// Dòng 2 gồm N số trong mảng A[]

// Constraints

// 1<=K<=N<=2.10^5

// 1<=A[i]<=10^9

// Output Format

// In ra N - K + 1 median của các dãy con

// Sample Input 0

// 8 2
// 7 6 6 2 9 6 2 7 
// Sample Output 0

// 6 6 2 2 6 2 2 
// Sample Input 1

// 6 1
// 7 2 9 2 4 6 
// Sample Output 1

// 7 2 9 2 4 6 