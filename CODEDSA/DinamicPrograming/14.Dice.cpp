// Tèo hiện đang học sinh lớp 10A1, vốn là một học sinh được đánh giá rất cao về khả năng toán học nên Tèo thường được các bạn trong lớp nhờ giải các bài toán trên tạp chí toán học và tuổi trẻ. Hôm nay Tí là bạn thân của Tèo gặp một bài toán trên tạp chí và đã nhờ Tèo giải hộ, Tèo dù rất giỏi toán và biết cách làm bài này nhưng bài toán này kết quả quá lớn nên Tèo phải nhờ tới bạn lập trình thuật toán để tìm ra lời giải giúp Tèo. Bài toán có yêu cầu rất đơn giản, cho ngẫu nhiên số N, hỏi rằng nếu được tung một con xúc xắc không giới hạn số lần và lấy tổng số chấm trên mặt xúc xắc cộng lại với nhau, hỏi có bao nhiêu cách tung để tổng số chấm trong mọi lần tung xúc xắc bằng N. Bạn hãy giúp Tèo giải quyết bài toán này nhé, vì số cách tung có thể quá lớn, nên bạn hãy chia dư kết quả với modulo 10^9 + 7

// Input Format

// Dòng duy nhất chứa số nguyên dương N

// Constraints

// 1<=N<=10^6;

// Output Format

// Kết quả của bài toán

// Sample Input 0

// 7
// Sample Output 0

// 63
// Sample Input 1

// 3
// Sample Output 1

// 4

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
int n;
int main(){
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("in.txt", "r", stdin);
	// for writing output to output.txt
	freopen("out.txt", "w", stdout);
	#endif
	cin >> n;
	ll dp[n+1] = {0};
	dp[0] = 1;
	 for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 6; j++){
            if (i - j >= 0){
                dp[i] = (dp[i] + dp[i-j]) % MOD;
            }
        }
    }
    cout << dp[n];
	return 0;
}