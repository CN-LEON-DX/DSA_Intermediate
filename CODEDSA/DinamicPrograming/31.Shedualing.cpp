// Có n dự án bạn có thể tham dự. Đối với mỗi dự án, bạn biết ngày bắt đầu và ngày kết thúc của dự án và số tiền bạn sẽ nhận được khi hoàn thành nó. Bạn chỉ có thể tham dự một dự án trong một ngày. Số tiền tối đa bạn có thể kiếm được là bao nhiêu?

// Input Format

// Dòng đầu tiên chứa số nguyên n: số lượng dự án. Sau đó, có n dòng. Mỗi dòng như vậy có ba số nguyên ai, bi và pi: ngày bắt đầu, ngày kết thúc và tiền thưởng.

// Constraints

// 1≤n≤2⋅10^5; 1≤ai≤bi≤10^9; 1≤pi≤10^9;

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 4
// 2 4 4
// 3 6 6
// 6 8 2
// 5 7 3
// Sample Output 0

// 7
// Sắp xếp các dự án theo thứ tự ngày kết thúc tăng dần. Nếu hai dự án có cùng ngày kết thúc, chọn dự án có ngày bắt đầu muộn hơn.

// Khởi tạo một mảng dp với kích thước n+1, với dp[i] là số tiền tối đa có thể kiếm được sau i dự án đầu tiên.

// Duyệt qua từng dự án, tìm dự án gần nhất mà kết thúc trước ngày bắt đầu của dự án hiện tại. Sử dụng tìm kiếm nhị phân để tìm dự án này.

// Cập nhật dp[i] bằng cách lấy max giữa dp[i-1] (nghĩa là không tham gia dự án hiện tại) và dp[j] + p[i] (nghĩa là tham gia dự án hiện tại, với j là dự án gần nhất kết thúc trước ngày bắt đầu của dự án hiện tại).

// Kết quả cuối cùng là dp[n], là số tiền tối đa có thể kiếm được sau tất cả các dự án.

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

struct duan{
    int begin, end, profit;
};

bool cmp(duan a, duan b){
    return a.end < b.end;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    vector<duan> x(n);
    for (duan &i : x){
        cin >> i.begin >> i.end >> i.profit;
    }
    sort(x.begin(), x.end(), cmp);
    vector<long long> dp(n+1, 0);
    dp[1] = x[0].profit;
    for (int i = 1; i < n; i++) {
        int j = lower_bound(x.begin(), x.begin() + i, duan{0, x[i].begin, 0}, cmp) - x.begin() - 1;
        dp[i+1] = max(dp[i], (j != -1 ? dp[j+1] : 0) + x[i].profit);
    }
    cout << dp[n];
    return 0;
}