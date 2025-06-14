#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int S[1001];
int check = 0;
void init(){
    for (int i = 1;i<=k;i++) S[i] = i;
}

void sinh(){
    int i = k;
    while (i>=1 && S[i] == n - k + i) --i;
    if (i==0) check = 1;
    else {
        S[i]++;
        for (int j = i+1;j<=k;j++){
            S[j] = S[j-1]+1;
        }
    }
}
int main() {
    cin >> n >> k;
    init();
    while (!check){
        for (int i = 1;i<=k;i++) cout << S[i];
        cout << endl;
        sinh();
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
// Cho hai số nguyên dương N và K. Nhiệm vụ của bạn là hãy liệt kê tất cả các tập con K phần tử của các số từ 1 tới N.

// Input Format

// 2 số nguyên dương N và K.

// Constraints

// 1<=K<=N<=15;

// Output Format

// In ra các tổ hợp trên từng dòng.

// Sample Input 0

// 5 2
// Sample Output 0

// 12
// 13
// 14
// 15
// 23
// 24
// 25
// 34
// 35
// 45