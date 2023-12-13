// Cho N bạn học sinh, giáo viên muốn xếp các bạn học sinh này vào một hàng ngang gồm N chiếc ghế. Nhiệm vụ của bạn là liệt kê các cách sắp xếp N bạn học sinh này theo thứ tự tên người tăng dần về thứ tự từ điển.

// Input Format

// Dòng đầu tiên là số N. Dòng thứ 2 là N tên học sinh, mỗi tên chỉ bao gồm một từ.

// Constraints

// 1<=N<=10;

// Output Format

// In ra các cách xếp trên từng dòng.

// Sample Input 0

// 3
// Lan Ngoc Nhung 
// Sample Output 0

// Lan Ngoc Nhung 
// Lan Nhung Ngoc 
// Ngoc Lan Nhung 
// Ngoc Nhung Lan 
// Nhung Lan Ngoc 
// Nhung Ngoc Lan 
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;

int n; 
string S[11];
int check = 0;
void init(){
    for (int i = 1;i<=n;i++) cin>> S[i];
    // DO đề bài yêu cầu xắp xếp giảm dần nên ta cần sort lại danh sách ban đầu để nó như cấu hình ban đầu 1,2,3
    // Thiếu là sai hết
    sort(S+1, S+n+1);
}
void sinh(){
    int i = n - 1;
    while (i>=1 && S[i] > S[i+1]) --i;
    if (i==0) check = 1;
    else{
        int j = n;
        while (S[i] > S[j]) --j;
        swap(S[i], S[j]);
        reverse(S+i+1, S+n+1);
    }
}
int main() {
    cin >> n;
    init();
    vector<string> vt;
    while (!check){
        string temp = "";
        for (int i = 1;i<=n;i++){
            temp+=S[i]+" ";
        }
        vt.push_back(temp);
        sinh();
    }
    for (string x : vt){
        cout << x << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

// CÁCH 2:
#include <bits/stdc++.h>
using namespace std;
int n; 
string S[11];

void init(){
    for (int i = 0; i < n; i++) cin >> S[i];
    sort(S, S+n);
}
int main() {
    cin >> n;
    init();
    do {
        for (int i = 0; i < n; i++){
            cout << S[i] << " ";
        }
        cout << endl;
    } while (next_permutation(S, S+n));
    return 0;
}
