// Source: https://usaco.guide/general/io

// 23 = 10111
#include <bits/stdc++.h>
using namespace std;
#define TIME cout << "\nTime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s"
int n;
int main() {
	int n; cin >> n;
	// 8 bit thì in từ 2^n-1 -> 0
	for (int i = 7;i>=0;--i){
		if ((n & (int)pow(2, i))!=0) cout << 1;
		else cout << 0;
	}
	return 0;
}
// Lý thuyết: https://www.youtube.com/watch?v=5P84A0YCo_Y
#include <bits/stdc++.h>
using namespace std;
// Sinh xâu nhị phân dài N mà dùng BIT
int main(){
	int n; cin >> n;
	for (int i = 0;i<(1<<n);i++){
		for (int j = n-1;j>=0;j--){
			if ((i & (1<<j))!=0) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
	return 0;
}
// 
// Sinh xâu nhị phân dài N mà dùng BIT
// Lại có thể dùng để sinh tập con 
// In ra tất cả các tập con của tập a
// Input:
5
1 2 3 4 5
// Output:

1 
2 
2 1 
3 
3 1 
3 2 
3 2 1 
4 
4 1 
4 2 
4 2 1 
4 3 
4 3 1 
4 3 2 
4 3 2 1 
5 
5 1 
5 2 
5 2 1 
5 3 
5 3 1 
5 3 2 
5 3 2 1 
5 4 
5 4 1 
5 4 2 
5 4 2 1 
5 4 3 
5 4 3 1 
5 4 3 2 
5 4 3 2 1 
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	int a[n];
	for (int i = 0;i<n;i++) cin >> a[i];
	for (int i = 0;i<(1<<n);i++){
		for (int j = n-1;j>=0;j--){
			if ((i & (1<<j))!=0) cout << a[j] << " ";
		}
		cout << endl;
	}
	return 0;
}