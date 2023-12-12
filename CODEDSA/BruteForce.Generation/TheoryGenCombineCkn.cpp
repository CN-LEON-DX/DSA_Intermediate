
// Yêu cầu: Hãy  liệt kê tất cả các cấu hình tổ hợp của C(k, n)

#include <bits/stdc++.h>
using namespace std;
int n, k;
int S[100];
bool checkfinal = 0;
// Thêm 
void init(){
	for (int i = 1;i<=k;i++){
		S[i] = i;
	}
}
void sinh(){
	int i = k;
	while (i>=1 && S[i] == n - k + i){
		i--;
	}
	if (i==0) checkfinal = 1;
	else {
		S[i]++;
		for (int j = i + 1;j<=k;j++){
			S[j] = S[j-1] + 1;
		}
	}0
	
}
int main() {
	cin >> n >> k; 
	init();
	while (!checkfinal){
		for (int i = 1;i<=k;i++){
			cout << S[i];
		}
		sinh();
		cout << endl;
	}
	return 0;
}