// [Mảng Cộng Dồn - Mảng Hiệu]. Bài 6. Tổng lớn nhất
// Problem
// Submissions
// Discussions
// Tèo đang làm các bài toán với truy vấn tổng trên đoạn, mỗi truy vấn yêu cầu các bạn tính tổng các phần tử từ chỉ số L tới chỉ số R, tuy nhiên bài toán này đã quá quen thuộc và dễ dàng có thể dùng mảng cộng dồn để giải quyết vì thế Tèo đưa ra thêm 1 yêu cầu cho bài toán.

// Cho trước các truy vấn tổng từ chỉ số L tới chỉ R, bây giờ bạn đã biết trước tất cả Q truy vấn bạn được phép thay đổi thứ tự các phần tử trong mảng 1 lần duy nhất trước khi thực hiện các truy vấn. Hãy thay đổi mảng sao cho tổng các truy vấn trên đoạn đạt được giá trị lớn nhất. Một cách rõ ràng hơn, bạn hãy tính tổng mọi mảng con trong từng truy vấn sau đó cộng lại để đạt được giá trị lớn nhất.

// Input Format

// Dòng 1 là N và Q

// Dòng 2 là N số trong mảng A[]

// Q dòng tiếp theo, mỗi dòng là 2 chỉ số L, R của truy vấn

// Constraints

// 1<=N,Q<=2.10^5

// 1<=A[i]<=2.10^5

// 1<=L<=R<=N

// Output Format

// In ra tổng lớn nhất có thể đạt được.

// Sample Input 0

// 6 2
// 5 2 5 3 5 1 
// 2 5
// 2 4
// Sample Output 0

// 33
// Explanation 0

// Thay đổi mảng A[] thành : {1, 5, 5, 5, 3, 2} 
//khi đó truy vấn từ 2 tới 5 là 18 và truy vấn từ 2 tới 4 là 15 nên tổng lớn nhất là 33.


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
    int n, m; cin >> n >> m;
    int a[n+1];
    for (int i = 1;i<=n;i++) cin >> a[i];
    int f[n+1] = {0};
    while (m--){
        int x, y; cin >> x >> y;
        f[x]++; f[y+1]--;
    }
    for (int i = 1;i<=n;i++) f[i]= f[i] + f[i-1];
    sort(f+1,f+n+1);
    sort(a+1,a+n+1);
    ll ans = 0;
    for (int i = 1;i<=n;i++) ans+=1ll*f[i]*a[i];
    cout << ans << nl;
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t=1;
    while (t--){
        slove();
    }
}