// Cho số tự nhiên N, hiện tại bạn được cung cấp một hoán vị của N phần tử các số từ 1 đến N. Nhiệm vụ của bạn là xác định xem hoán vị này là hoán vị thứ bao nhiêu nếu bạn sinh ra tất cả các hoán vị của tập N phần tử. Ví dụ với N = 3, thì hoán vị 132 là hoán vị thứ 2.

// Input Format

// Dòng đầu tiên là số nguyên dương N. Dòng thứ 2 là N số nguyên của cấu hình hiện tại

// Constraints

// 1<=N<=10;

// Output Format

// In ra số thứ tự của hoán vị được cho

// Sample Input 0

// 3
// 3 1 2 
// Sample Output 0

// 5

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int S[11];
int check = 0;
int n;
void init(){
    for (int i = 1;i<=n;i++) S[i] = i;
}
void sinh(){
    int i = n - 1;
    while (i>=1 && S[i] > S[i+1]) --i;
    if (i==0) check = 1;
    else {
        int j = n;
        while (S[i] > S[j]) --j;
        swap(S[i], S[j]);
        reverse(S+i+1, S+n+1);
    }
}

int main() {
    cin >> n;
    string s = "";
    init();
    for (int i = 1;i<=n;i++){
        int k; cin >> k;
        s+=to_string(k);
    }
    vector<string> vt;
    int i = 1;
    while (!check){
        string temp = "";
        for (int t = 1;t<=n;t++) temp += to_string(S[t]);
        if (temp==s){
            cout << i;
            break;
        }
        i++;
        sinh();
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

// CÁCH 2;
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    int rank = 1;
    do {
        if (b == a) {
            cout << rank << endl;
            return 0;
        }
        rank++;
    } while (next_permutation(b.begin(), b.end()));
    return 0;
}