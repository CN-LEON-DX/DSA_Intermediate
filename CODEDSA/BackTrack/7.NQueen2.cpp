// Cho một bàn cờ 8 x 8, mỗi ô có một giá trị A[i][j] nhất định (0 ≤ A[i][j] ≤ 100), tương ứng với điểm số đạt được nếu như bạn đặt một quân cờ vào đó. Nhiệm vụ của bạn là đặt 8 quân hậu lên bàn cờ, sao cho không có 2 quân nào ăn nhau, và số điểm đạt được là lớn nhất.

// Input Format

// Gồm 8 dòng, mỗi dòng gồm 8 số tương ứng với các số trên bàn cờ.

// Constraints

// 1<=A[i][j]<=100;

// Output Format

// In ra số điểm đạt được lớn nhất.

// Sample Input 0

// 12 29 80 91 56 46 97 13 
// 54 88 27 84 85 9 32 77 
// 48 80 88 74 30 77 38 98 
// 6 82 20 95 7 86 12 43 
// 100 82 15 7 95 9 5 84 
// 51 40 65 98 86 38 30 63 
// 96 78 98 76 33 11 2 58 
// 33 51 35 68 62 87 67 39 
// Sample Output 0

// 653
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int n = 8, X[100], cot[100], xuoi[100], nguoc[100];
int a[9][9];
ll res = -1;
void Try(int i){
    for (int j = 1;j<=n;j++){
        if (cot[j] == 0 && xuoi[i - j + n]==0 && nguoc[i + j - 1] == 0){
            X[i] = j;
            cot[j] = 1;
            xuoi[i-j+n] = 1;
            nguoc[i+j-1] = 1;
            ll temp = 0;
            if (i==n){
                for (int i=1;i<=8;i++){
                    temp+=a[i][X[i]];
                }
                res = max(temp, res);
            }else{
                Try(i+1);
            }
            cot[j] = 0;
            xuoi[i-j+n] = 0;
            nguoc[i+j-1] = 0;
        }
    }
}
int main() {
    for (int i = 1;i<=8;i++){
        for (int j = 1;j<=8;j++){
            cin >> a[i][j];
        }
    }
    Try(1);
    cout << res;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

