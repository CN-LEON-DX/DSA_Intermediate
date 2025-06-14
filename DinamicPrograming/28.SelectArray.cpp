// Bạn biết rằng một mảng có n số nguyên chỉ gồm các số từ 1 đến m và độ lệch giữa 2 phần tử liền kề trong mảng không được vượt quá 1 đơn vị. Bài toán đặt ra đó là cho bạn một mảng trong đó một số giá trị trong mảng chưa được xác định giá trị, nhiệm vụ của bạn là đếm số mảng phù hợp với mô tả, đó là các số liền kề trong mảng không lệch nhau quá 1 đơn vị và các giá trị trong mảng chỉ được nằm trong đoạn từ 1 tới m.

// Input Format

// Dòng nhập đầu tiên có hai số nguyên n và m: kích thước mảng và giới hạn trên cho mỗi giá trị.

// Dòng tiếp theo có n số nguyên x1, x2,…, xn: nội dung của mảng. Giá trị 0 biểu thị một giá trị không xác định.
// Constraints
// 1≤n≤10^5;
// 1≤m≤100; 0≤xi≤m;
// Output Format
// In ra số lượng mảng phù hợp sau khi chia dư cho 1e9 + 7
// Sample Input 0
// 3 5
// 2 0 2
// Sample Output 0
// 3
// Explanation 0
// Các mảng có thể thỏa mãn : [2, 1, 2], [2, 2, 2], [2, 3, 2]
// Bài toán này có thể được giải quyết bằng cách sử dụng quy hoạch động. 
// Ý tưởng chính là tạo ra một bảng quy hoạch động dp[i][j] với ý nghĩa là số cách để điền các số vào mảng từ vị trí 1 đến i sao cho số cuối cùng là j.
// Dưới đây là cách cài đặt thuật toán:
// Khởi tạo mảng dp với kích thước (n+1) x (m+1) và tất cả các giá trị đều bằng 0. dp[0][0] = 1.
// Duyệt qua mảng từ vị trí 1 đến n. Với mỗi vị trí i, duyệt qua tất cả các giá trị j từ 1 đến m.
// Nếu mảng tại vị trí i bằng 0 hoặc bằng j, thì dp[i][j] sẽ bằng tổng của dp[i-1][j-1], dp[i-1][j] và dp[i-1][j+1].
// Nếu không, dp[i][j] = 0.
// Tổng của dp[n][j] với j từ 1 đến m sẽ là kết quả.
#include <bits/stdc++.h>
using namespace std;
// Run Time 
#define TIME cout << "\nTime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s"
// Debug
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
typedef pair<int,int> ii;
const int dx[4] = {-1, +0, +1, +0};
const int dy[4] = {+0, +1, +0, -1};
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1};
const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};
const int MOD = 1e9+7;
typedef long long ll;
int n, m;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(m+2, 0));
    if (a[1] == 0) {
        fill(dp[1].begin() + 1, dp[1].begin() + m + 1, 1);
    } else {
        dp[1][a[1]] = 1;
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j]) % MOD + dp[i-1][j+1]) % MOD;
            }
        } else {
            dp[i][a[i]] = ((dp[i-1][a[i]-1] + dp[i-1][a[i]]) % MOD + dp[i-1][a[i]+1]) % MOD;
        }
    }
    int res = 0;
    for (int j = 1; j <= m; j++) {
        res = (res + dp[n][j]) % MOD;
    }
    cout << res << endl;
	return 0;
}
