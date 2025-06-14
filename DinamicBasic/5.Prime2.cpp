// Cho 2 số nguyên L, R, hãy đếm xem trong đoạn từ L tới R có bao nhiêu số nguyên tố.

// Gợi ý :

// Bước 1 : Sàng số nguyên tố

// Bước 2 : Gọi F[i] là số các nguyên tố từ 0 tới i, khi đó số các số nguyên tố từ L tới R là F[R] - F[L - 1]

// Input Format

// Dòng 1 là số bộ test T

// T dòng tiếp theo mỗi dòng là 2 số nguyên không âm L, R

// Constraints

// 1<=T<=10000

// 0<=L<=R<=10^6

// Output Format

// Đưa ra kết quả của mỗi test trên 1 dòng

// Sample Input 0

// 5
// 3 19
// 4 65
// 4 44
// 1 17
// 1 7
// Sample Output 0

// 7
// 16
// 12
// 7
// 4
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int INT = 1000001;
int n, l, r;
int F[INT+1], D[INT+1];
void sang(){
    for (int i = 0;i<=INT;i++) F[i] = 1;
    F[0] = 0;
    F[1] = 0;
    for (int i = 2;i<=sqrt(INT);i++){
        if (F[i]){
            for (int j = i*i;j<=INT;j+=i) F[j]=0;
        }
    }
    D[0] = 0;
    D[1] = 0;
    for (int i = 2;i<=INT;i++){
        if (F[i]){
            D[i] = D[i-1]+1;
        }else{ D[i] = D[i-1];}
    }
}

int main() {
    cin >> n;
    sang();
    while (n--){
        cin >> l >> r;
        cout << D[r] - D[l-1] << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}