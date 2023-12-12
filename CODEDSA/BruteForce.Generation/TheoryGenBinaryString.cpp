
// Yêu cầu: Hãy liệt kê tất cả các xâu nhị phân có độ dài n bit 
#include <bits/stdc++.h>
using namespace std;
int n;
int S[100];
bool checkfinal = 0;
void init(){
	for (int i = 1;i<=n;i++){
		S[i] = 0;
	}
}
void sinh(){
	int i = n;
	while (i>=1 && S[i]==1){
		S[i]=0;
		--i;
	}
	if (i==0) checkfinal = 1;
	else S[i] = 1;
}
int main() {
	cin >> n; 
	init();
	while (!checkfinal){
		sinh();
		for (int i = 1;i<=n;i++){
			cout << S[i];
		}
		cout << endl;
	}
	return 0;
}