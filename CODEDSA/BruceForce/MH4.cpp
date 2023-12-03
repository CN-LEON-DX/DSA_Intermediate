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
    int n, m, k; cin >> n >> m >> k;
    int f[200001] = {0};
    int t = n;
    int maxe = -1;
    while (t--){
        int x, y; cin >> x >> y;
        maxe = max(maxe, y);
        f[x]+=1; f[y+1]-=1;
    }
    for (int i = 1;i<=200000;i++) f[i]= f[i] + f[i-1];
    int dp[200001] = {0};
    for (int i = 1;i<=200000;i++){
        if (f[i]>=m){
            dp[i] = 1;
        }else dp[i] = 0;
    }
    for (int i = 1;i<=200000;i++) dp[i]+=dp[i-1];
    while (k--){
        int x, y; cin >> x >> y;
        cout << dp[y] - dp[x-1] << nl;
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

// [Mảng Cộng Dồn - Mảng Hiệu]. Bài 7. Pha Trà Sữa
// Problem
// Submissions
// Discussions
// Tèo mới lên đại học và kiếm được một công việc tại hàng trà sữa, có không quá 200000 cốc trà sữa xếp thành 1 hàng ngang, ban đầu mỗi cốc trà sữa có độ ngọt bằng 0. Tèo tiến hành liên tiếp N các thao tác, mỗi thao tác anh ta sẽ thêm 1 gam đường vào các cốc trà sữa từ vị trí L tới vị trí R. Sau cùng những cốc trà sữa có lượng đường >= K gam được chuyển đi để phục vụ khách hàng. Có nhiều câu hỏi, mỗi câu hỏi yêu cầu bạn trả lời trong các cốc trà từ thứ L tới thứ R có bao nhiêu cốc đạt chuẩn để bán cho khách hàng ?

// Input Format

// Dòng 1 gồm 3 số N, K, Q với Q là số truy vấn

// N dòng tiếp theo mỗi dòng gồm 2 số L, R (thao tác)

// Q dòng tiếp theo mỗi dòng là 2 số L, R (truy vấn)

// Constraints

// 1<=K<=N<=200000

// 1<=Q<=200000

// 1<=L,R<=200000

// Output Format

// Đối với mỗi truy vấn in ra số lượng cốc trà sữa đạt chuẩn

// Sample Input 0

// 5 3 4
// 2 9
// 5 8
// 2 4
// 2 4
// 1 6
// 3 4
// 5 7
// 5 8
// 5 8
// Sample Output 0

// 2
// 2
// 2
// 2