// Segment Tree linh hoạt và mạnh hơn Fenwick Tree nhưng nó lại dài và khó cài đặt hơn !
// Hay áp dụng cho các bài liên quan đến truy vấn mảng như tính tổng các mảng con từ l -> r 
// Trong khi tính thường có các yêu cầu thêm như chỉnh sửa phần tử ...
// Thêm vào đó code này thật ra ko tối ưu bằng prefixsum nhưng lại có hữu dụng lớn với các bài cần thêm các yêu cầu mỗi truy vấn 
// Với độ phức tạp code: + Khi khởi tạo là O log(N), Còn khi truy vấn thì mất OlogN
// Ví dụ với bài sau: 
// Yêu cầu:
// Query: Tính tổng các phần tử trong đoạn con của mảng.
// Update: Cập nhật giá trị của một phần tử trong mảng.
// Input Format:
// Dòng đầu tiên: Số nguyên 
// N - kích thước của mảng.
// Dòng thứ hai: 
// N số nguyên, là giá trị của các phần tử trong mảng.
// Dòng thứ ba: Số nguyên 
// Q dòng tiếp theo: Mỗi dòng mô tả một truy vấn. Có thể là truy vấn loại "Query" hoặc "Update".
// Output Format:
// Với mỗi truy vấn "Query", in ra tổng của đoạn con được chỉ định.
// Không có output cho truy vấn "Update".
// Ví dụ:
// Input:
// Copy
// 5
// 1 3 5 7 9
// 3
// Query 2 4
// Update 3 6
// Query 1 5
// Output:
// 15
// 27
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
const int maxi = 2e5;
typedef long long ll;
int n;
int a[maxi];
int Tree[4 * maxi];
void build(int node, int l, int r){
	if (l == r){
		Tree[node] = a[l];
	}else{
		int mid = (l + r) / 2; 
		build(2 * node, l, mid);
		build(2 * node + 1, mid+1, r);
		Tree[node] = Tree[2*node] + Tree[2*node + 1];
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	cin >> n;
	for (int i = 1; i<= n; i ++ ) cin >> a[i];
	build(1, 1, n);
	for (int i = 1; i<= 20;i++) cout << Tree[i] << " ";
	return 0;
}