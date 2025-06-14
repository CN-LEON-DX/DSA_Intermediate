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

int findMostLeft(int a[], int l, int r, int x){
    int left = -1;
    while (l <= r){
        int mid = (l + r) / 2;
        if (a[mid] == x){
            left = mid;
            r = mid - 1;
        }else if (a[mid] < x) {
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return left;
}

int findMostRight(int a[], int l, int r, int x){
    int right = -1;
    while (l <= r){
        int mid = (l + r) / 2;
        if (a[mid] == x){
            right = mid;
            l = mid + 1;
        }else if (a[mid] < x) {
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return right;
}

void solve(){
    int n, m; cin >> n >> m;
    int a[n+1];
    int b[m+1];
    map<int, int> mp;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        mp[b[i]]++;
    }
    ll cnt = 0;
    for (auto x : mp){
        if (findMostLeft(a, 1, n, x.first) != -1){
            int time =  findMostRight(a, 1, n, x.first) - findMostLeft(a, 1, n, x.first) + 1;
            cnt += 1ll * time * x.second;
            mp[x.first] = 0;
        }
    }
    cout << cnt << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    solve();
    return 0;
}
// Cho 2 mảng A[] và B[] có N và M phần tử đã được sắp xếp theo thứ tự tăng dần, nhiệm vụ của bạn là hãy đếm xem trong 2 mảng tồn tại bao nhiêu cặp i, j sao cho A[i] = B[j]

// Input Format

// Dòng đầu tiên là N và M

// Dòng 2 là N số trong mảng A[]

// Dòng 3 là M số trong mảng B[]

// Constraints

// 1<=N,M<=10^7

// 1<=A[i],B[i]<= 10^9

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 6 7
// 3 3 3 4 7 9 
// 2 3 3 5 6 9 10 
// Sample Output 0

// 7