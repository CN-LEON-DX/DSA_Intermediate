// Cho một bàn cờ vua có kích thước n * n. Vấn đề đặt ra rằng, có n quân hậu, bạn cần đếm số cách đặt n quân hậu này lên bàn cờ sao cho với 2 quân hậu bất kì, chúng không “ăn” nhau.

// Input Format

// Dòng duy nhất chứa n là kích thước của bàn cờ.

// Constraints

// 1<=N<=12

// Output Format

// In ra số cách xếp hậu hợp lệ

// Sample Input 0

// 8
// Sample Output 0

// 92

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int X[100];
int cot[100], xuoi[100], nguoc[100];
int cnt = 0;
void Try(int i){
    for (int j = 1;j<=n;j++){
        if (cot[j]== 0 && xuoi[i-j+n]==0 && nguoc[i+j-1]==0){
            X[i] = j;
            cot[j]=1;
            xuoi[i-j+n] = 1;
            nguoc[i+j-1] = 1;
            if (i==n){
                ++cnt;
            }else{
                Try(i+1);
            }
            // backtrack
            cot[j]=0;
            xuoi[i-j+n] = 0;
            nguoc[i+j-1] = 0;
        }
    }
}

int main() {
    cin >> n;
    Try(1);
    cout << cnt;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
