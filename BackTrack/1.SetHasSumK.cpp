// Xét tất cả các tập hợp các số nguyên dương có các phần tử khác nhau và không lớn hơn số n cho trước. Nhiệm vụ của bạn là hãy đếm xem có tất cả bao nhiêu tập hợp có số lượng phần tử bằng k và tổng của tất cả các phần tử trong tập hợp bằng s? Các tập hợp là hoán vị của nhau chỉ được tính là một. Ví dụ với n = 9, k = 3, s = 23, {6, 8, 9} là tập hợp duy nhất thỏa mãn.

// Input Format

// 1 dòng gồm 3 số nguyên n, k, s

// Constraints

// 1 ≤ n ≤ 20, 1 ≤ k ≤ 10 và 1 ≤ s ≤ 155

// Output Format

// In ra số lượng các tập hợp thỏa mãn điều kiện đề bài.

// Sample Input 0

// 16 8 91
// Sample Output 0

// 28

#include <cmath>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int n, k, s;
int X[21];
int dem = 0;
void Try(int i){
    for (int j = X[i-1] + 1; j<=n-k+i;j++){
        X[i] = j;
        if (i==k){
            int s1 = 0;
            for (int t = 1;t<=k;t++){
                s1+=X[t];
            }
            if (s1==s) dem++;
        }
        else Try(i+1);
    }
}
int main() {
    cin >> n >> k >> s;
    Try(1);
    cout << dem;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
