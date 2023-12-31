#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int S[10];
int n, k, check = 0;
void init(){
    for (int i = 1;i<=k;i++){
        S[i] = 1;
    }
}
void sinh(){
    int i = k;
    while (i>=1 && S[i]==n){
        --i;
    }
    if (i==0) check = 1;
    else{
        S[i]++;
        for (int j = i+1;j<=k;j++){
            S[j] = 1;
        }
    }
}
int main() {
    cin >> n  >> k;
    init();
    while (!check){
        for (int i = 1;i<=k;i++){
            cout << S[i];
        }
        cout << endl;
        sinh();
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
// Cho 2 số nguyên dương N và K. Nhiệm vụ của bạn là sinh ra chỉnh hợp lặp chập K của N phần tử gồm các số tự nhiên từ 1 đến N. Ví dụ N = 3, K = 2 bạn sẽ có các kết quả là : 11, 12, 13, 21, 22, 23, 31, 32, 33. Số chỉnh hợp lặp chập K của N sẽ là N^K.

// Input Format

// 1 dòng duy nhất chứa 2 số nguyên dương N và K.

// Constraints

// 1<=K,N<=8

// Output Format

// In ra các cấu hình của chỉnh hợp lặp chập K của N

// Sample Input 0

// 2 4
// Sample Output 0

// 1111
// 1112
// 1121
// 1122
// 1211
// 1212
// 1221
// 1222
// 2111
// 2112
// 2121
// 2122
// 2211
// 2212
// 2221
// 2222