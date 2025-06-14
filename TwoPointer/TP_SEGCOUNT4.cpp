
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
    fore(i, 0, n) cin >> a[i];
    ll cnt = 0;
    int l = 0;
    multiset<int> ms;
    for (int r = 0;r<n;r++){
        ms.insert(a[r]);
        while (ms.size() > 1 && (*ms.rbegin()-*ms.begin()) > k ){
            // Xóa từ bên trái sang vì nó cần sự liên tiếp 
            auto it = ms.find(a[l]);
            // Do là nó sắp xếp không theo thứ tự ban đầu nên ta cần dùng find
            ms.erase(it);
            l++;
        }
        cnt += r - l + 1;
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t = 1;
    while (t--){
        slove();
    }
}

// Cho mảng A[] gồm N số nguyên và số nguyên K, nhiệm vụ của bạn là đếm xem có bao nhiêu mảng con các phần tử liên tiếp trong mảng mà độ chênh lệch giữa phần tử lớn nhất và phần tử nhỏ nhất trong mảng con đó không vượt quá K

// Input Format

// Dòng đầu tiên là N và K

// Dòng thứ 2 là N số trong mảng A[]

// Constraints

// 1<=N<=10^5

// 1<=A[i],K<=10^6

// Output Format

// In ra số lượng mảng con thỏa mãn đề bài

// Sample Input 0

// 10 1
// 2 3 1 3 1 4 1 3 1 2 
// Sample Output 0

// 12