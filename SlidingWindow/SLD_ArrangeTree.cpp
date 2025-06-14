// Nhà Tèo ở gần bờ sông, trên bờ sông có trồng N cây phi lao, tuy nhiên có những cây không thể sống được do thời tiết khắc nghiệt của mùa đông miền Bắc. Một ngày nọ Tèo đi dọc bờ sông và tự hỏi, liệu rằng có thể tìm được K cây phi lao con còn sống liên tiếp dọc bờ sông hay không. Có thể sẽ không tồn tại K cây phi lao con còn sống liên tiếp, vì thế Tèo sẽ chuyển những cây phi lao con còn sống ở những ô khác để tạo ra một dãy các cây phi lao sống liên tiếp. Bạn hãy giúp Tèo di chuyển ít nhất cây phi lao nhất có thể, hoặc xác định rằng không thể di chuyển các cây phi lao còn sống lại gần nhau để tạo ra K cây phi lao liên tiếp còn sống.

// Input Format

// Dòng 1 là N và K

// Dòng 2 mô tả N cây phi lao, 0 tương ứng với cây phi lao chết, 1 tương ứng với cây phi lao sống.

// Constraints

// 1<=K<=N<=10^6
// Output Format

// In ra số cây phi lao ít nhất cần di chuyển hoặc in ra -1 nếu không thể tạo ra 1 dãy K cây phi lao còn sống.

// Sample Input 0

// 11 3
// 0 0 0 0 1 0 1 0 0 0 1 
// Sample Output 0

// 1
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

void solve(){
    
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t=1;
    while (t--){
        solve();
    }
}