// Cho 2 số nguyên dương N và K và một tổ hợp K phần tử của tập N phần tử các số từ 1 tới N. Bạn hãy xác định xem tổ hợp đã cho có số thứ tự bao nhiêu nếu xếp các tổ hợp chập K của N theo thứ tự ngược. Ví dụ N = 5, K = 3 và tổ hợp đã cho là (2, 3, 4) sẽ là tổ hợp có số thứ tự 4.

// Input Format

// Dòng đầu gồm 2 số nguyên dương N và K. Dòng thứ 2 gồm K số mô tả tổ hợp đã cho. Dữ liệu đảm bảo tổ hợp đã cho là hợp lệ.

// Constraints

// 1<=K<=N<=15;

// Output Format

// In ra số thứ tự của tổ hợp

// Sample Input 0

// 12 4
// 8 9 10 11 
// Sample Output 0

// 5


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int n, k;
int S[16];
int check = 0;
void init(){
    for (int i = 1;i<=k;i++){
        S[i] = i;
    }
}
void sinh(){
    int i = k;
    while (i>=1 && S[i] == n - k + i) --i;
    if (i==0) check = 1;
    else{
        S[i]++;
        for (int j = i+1;j<=k;j++){
            S[j] = S[j-1]+1;
        }
    }
}
int main() {
    cin >> n >> k;
    init();
    string s="";
    for (int i = 1;i<=k;i++) {
        int x; cin >> x;
        s+=to_string(x);
    }
    vector<string> vt;
    while (!check){
        string temp = "";
        for (int i = 1;i<=k;i++){
            temp+=to_string(S[i]);
        }
        vt.push_back(temp);
        sinh();
    }
    reverse(vt.begin(), vt.end());
    for (int i = 0;i<vt.size();i++){
        if (vt[i] == s){
            cout << i+1;
            break;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
