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
    ll sum = 0;
    int l = 0;
    fore(i, 0, n) cin >> a[i];
    int mindis = -1;
    for (int r = 0;r<n;r++){
        sum+=a[r];
        while (sum >= s){
            sum-=a[l];
            mindis = (mindis == -1) ? r - l + 1 : min(mindis, r - l + 1);
            l++;
        }
    }
    cout << mindis << nl;
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t = 1;
    while (t--){
        slove();
    }
}


// Nhân dịp lễ Giáng Sinh 2022, 28Tech tổ chức phát quà cho các bạn nhỏ. Có N món quà được xếp thành hàng ngang, mỗi món quà đều có khối lượng cho trước. Tí là một đứa trẻ không như nhiều đứa trẻ khác, Tí chỉ muốn chọn ít phần quà càng tốt miễn là tổng các phần quà này lớn hơn hoặc bằng S. Tí chỉ có thể lựa chọn các phần quà đặt cạnh nhau, bạn hãy xác định xem Tí có thể chọn tối thiểu bao nhiêu phần quà để tổng khối lượng của các phần quà lớn hơn hoặc bằng S.

// Input Format

// Dòng đầu tiên là N và S

// Dòng thứ 2 là trọng lượng của N phần quà

// Constraints

// 1<=N<=10^6

// 1<=S<=10^9

// Trọng lượng các phần quà là số nguyên dương không quá 10^6

// Output Format

// In ra số lượng phần quà ít nhất có thể hoặc in ra -1 nếu không tồn tại đáp án.

// Sample Input 0

// 14 14
// 4 4 5 1 3 1 3 4 1 1 5 4 1 4 
// Sample Output 0

// 4