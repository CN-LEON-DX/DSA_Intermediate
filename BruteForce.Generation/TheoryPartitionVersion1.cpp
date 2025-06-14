#include <bits/stdc++.h>
using namespace std;

// Phân hoạch một số N thành các số có tổng bằng N
// Input: 6
// Output:
// 10 
// 9 1 
// 8 2 
// 8 1 1 
// 7 3 
// 7 2 1 
// 7 1 1 1 
// 6 4 
// 6 3 1 
// 6 2 2 
// 6 2 1 1 
// 6 1 1 1 1 
// 5 5 
// 5 4 1 
// 5 3 2 
// 5 3 1 1 
// 5 2 2 1 
// 5 2 1 1 1 
// 5 1 1 1 1 1 
// 4 4 2 
// 4 4 1 1 
// 4 3 3 
// 4 3 2 1 
// 4 3 1 1 1 
// 4 2 2 2 
// 4 2 2 1 1 
// 4 2 1 1 1 1 
// 4 1 1 1 1 1 1 
// 3 3 3 1 
// 3 3 2 2 
// 3 3 2 1 1 
// 3 3 1 1 1 1 
// 3 2 2 2 1 
// 3 2 2 1 1 1 
// 3 2 1 1 1 1 1 
// 3 1 1 1 1 1 1 1 
// 2 2 2 2 2 
// 2 2 2 2 1 1 
// 2 2 2 1 1 1 1 
// 2 2 1 1 1 1 1 1 
// 2 1 1 1 1 1 1 1 1 
// 1 1 1 1 1 1 1 1 1 1 

int n;
int X[1001];
int cnt = 0;
int check = 0;
void init(){
    cnt++;
    X[1] = n;
}
void sinh(){
    int i = cnt;
    while (i>=1 && X[i] == 1){
        --i;
    }
    if (i==0) check = 1;
    else {
        X[i]--;
        int d = cnt - i + 1;
        cnt = i;
        int p = d/X[i], r = d%X[i];
        for (int j=1;j<=p;j++){
            cnt++;
            X[cnt] = X[i];
        }
        if (r){
            ++cnt;
            X[cnt] = r;
        }
    }
}
int main() {
    cin >> n;
    init();
    while (!check){
        for (int i = 1;i<=cnt;i++){
            cout << X[i] << " ";
        }
        cout << endl;
        sinh();
    }
    return 0;
}