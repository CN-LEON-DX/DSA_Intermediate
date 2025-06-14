// Cho số nguyên dương N, hãy đếm xem trong đoạn từ 0 tới N có bao nhiêu số nguyên tố. Hướng dẫn :

// Bước 1 : Sàng số nguyên tố

// Bước 2 : Gọi F[i] là số lượng các số nguyên tố từ 0 tới i, xây dựng mảng F[i] sau khi sàng

// Input Format

// Dòng 1 là số bộ test T

// T dòng tiếp theo mỗi dòng là 1 số nguyên không âm N

// Constraints

// 1<=T<=10000

// 0<=N<=10^6

// Output Format

// Đưa ra kết quả của mỗi test trên 1 dòng

// Sample Input 0

// 5
// 39
// 68
// 26
// 87
// 6
// Sample Output 0

// 12
// 19
// 9
// 23
// 3
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int INT = 1000001;
int n, k;
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
        cin >> k;
        cout << D[k] << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
