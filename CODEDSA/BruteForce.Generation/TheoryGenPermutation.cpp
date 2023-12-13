

// Liệt kê tấn cả hoán vị của các số từ 1 đến n
#include <bits/stdc++.h>
using namespace std;
#define TIME cout << "\nTime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s"
int n;
int S[100];
bool checkfinal = 0;
void init(){
	for (int i = 1;i<=n;i++){
		S[i] = i;
	}
}
void sinh(){
	int i = n-1;
	while (i>=1 && S[i] > S[i+1]) --i;
	if (i==0) checkfinal = 1;
	else {
		int j = n;
		while (S[i] > S[j]) --j;// tim pt lon nhat mà lớn hơn S[i]
		swap(S[i], S[j]);// Sau đó hoán đổi chúng
		// sort hay reverse(S+i+1, S+n+1) = sort do mảng đoạn đó giảm dần
		// Nếu sort thì phải sort
		sort(S+i+1, S+n+1);
        // Hoặc reverse
		//reverse(S+i+1, S+n+1);
	}
}
int main() {
	cin >> n;
	init();
	cout << n << endl;
	while (!checkfinal){
		for (int i = 1;i<=n;i++){
			cout << S[i];
		}
		cout << endl;
		sinh();
	}
	return 0;
}

// CODE ngắn gọn
// Vẫn mất khoảng 0.001s
#include <bits/stdc++.h>
using namespace std;
#define TIME cout << "\nTime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s"
int n;
int main() {
	int S[] = {1, 2, 3, 4};
	TIME;
	int n = 4;
	do{
		for (int i = 0;i<n;i++) cout << S[i];
		cout << endl;
	}while (next_permutation(S, S+n));
	TIME;
	return 0;
}