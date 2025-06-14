// Cho cây nhị phân, nhiệm vụ của bạn là duyệt cây theo thứ tự Inorder. Thứ tự duyệt Inorder của cây nhị phân bên dưới xuất hiện trong test case mẫu.

// image

// Input Format

// Dòng đâu tiên là N : số lượng cạnh của cây. Các dòng tiếp theo mô tả cây nhị phân bằng 3 số (x, y, z) : x là node cha, y là node con, z có thể nhận 1 trong 2 giá trị là L và R, tương ứng với y là node con bên trái hoặc node con bên phải của x.

// Constraints

// 1<=N<=1000; 1<=x,y<=10^5;

// Output Format

// In ra thứ tự duyệt cây Inorder

// Sample Input 0
// 6
// 1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R
// Sample Output 0
// 4 2 5 1 6 3 7
#include <bits/stdc++.h>
using namespace std;
// Run Time 
#define TIME cout << "\nTime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s"
// Debug
void __print(int x) {cerr << x;} void __print(long x) {cerr << x;} void __print(long long x) {cerr << x;} void __print(unsigned x) {cerr << x;} void __print(unsigned long x) {cerr << x;} void __print(unsigned long long x) {cerr << x;} void __print(float x) {cerr << x;} void __print(double x) {cerr << x;} void __print(long double x) {cerr << x;} void __print(char x) {cerr << '\'' << x << '\'';} void __print(const char *x) {cerr << '\"' << x << '\"';} void __print(const string &x) {cerr << '\"' << x << '\"';} void __print(bool x) {cerr << (x ? "true" : "false");} template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T> void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";} void _print() {cerr << "]\n";}
template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
typedef pair<int,int> ii;
const int dx[4] = {-1, +0, +1, +0}; const int dy[4] = {+0, +1, +0, -1};
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1}; const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};
const int MOD = 1e9+7; typedef long long ll;
int n;
struct node{
	int val;
	node *left;
	node *right;
	node (int x) {
		val = x;
		left = right = NULL;
	}
};
void MakeRoot(node *root, int v, char c){
	if (c=='L') root->left = new node(v);
	else root->right = new node(v);
}
void InsertNode(node *root, int u, int v, char c){
	if (root != NULL) return;
	if (root->val == u){
		MakeRoot(root, v, c);
	}else{
		InsertNode(root->left, u, v, c);
		InsertNode(root->right, u, v, c);
	}
}
void LNR(node *root){
	if (root==NULL) return;
	LNR(root->left);
	cout << root->val << " ";
	LNR(root->right);
}

int main(){
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("in.txt", "r", stdin);
	// for writing output to output.txt
	freopen("out.txt", "w", stdout);
	#endif
	cin >> n;
	node *root = NULL;
	while (n--){
		int u, v; char c; 
		cin >> u >> v >> c;
		cout << u << " " << v << " " << c << endl;
		if (root==NULL){
			root = new node(u);
			MakeRoot(root, v, c);
		}else{
			InsertNode(root, u, v, c);
		}
	}
	LNR(root);
	return 0;
}