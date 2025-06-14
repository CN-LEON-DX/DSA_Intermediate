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
    int n, s; cin >> n >> s;
    int a[n];
    fore(i, 0, n) cin >> a[i];
    int l = 0;
    ll sum = 0;
    int maxdis = 0;
    for (int r = 0;r<n;r++){
        sum+=a[r];
        while (sum>s){
            sum-=a[l];
            l++;
        }
        maxdis = max(maxdis, r - l + 1);
    }
    cout << maxdis << nl;
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t=1;
    while (t--){
        slove();
    }
}
// Nhân dịp lễ Giáng Sinh 2022, 28Tech tổ chức phát quà cho các bạn nhỏ. Có N món quà được xếp thành hàng ngang, mỗi món quà đều có khối lượng cho trước. Tèo là một đứa trẻ cũng như nhiều đứa trẻ khác chỉ muốn có càng nhiều phần quà càng tốt, không cần biết tới khối lượng của từng mốn quà nặng nhẹ ra sao.

// Tuy nhiên chiếc túi của Tèo chỉ mảng được trọng lượng tối đa là S. Bạn hãy xác định xem số lượng phần quà mà Tèo có thể lựa chọn tối đa là bao nhiêu để có thể không vượt quá trọng lượng tối đa mà cái túi có thể chịu được. Ngoài ra trong lúc chọn quà Tèo chỉ có thể chọn các phần quà xếp cạnh nhau mà thôi.

// Input Format

// Dòng đầu tiên là N và S

// Dòng thứ 2 là trọng lượng của N phần quà

// Constraints

// 1<=N<=10^6

// 1<=S<=10^9

// Trọng lượng các phần quà là số nguyên dương không quá 10^6

// Output Format

// In ra số phần quà tối đa mà Tèo có thể lấy được

// Sample Input 0

// 11 10
// 3 1 4 1 5 3 4 1 5 2 2 
// Sample Output 0

// 4