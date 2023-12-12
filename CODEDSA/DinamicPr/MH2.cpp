// Cho mảng số nguyên A[] gồm N phần tử, có Q thao tác, mỗi thao tác yêu cầu các bạn tăng tất cả các phần tử từ chỉ số L tới chỉ số R lên K đơn vị. Bạn hãy in ra mảng sau khi thực hiện các thao tác trên.

// Input Format

// Dòng 1 là N và Q

// Dòng 2 là N phần tử trong mảng A[]

// Q dòng tiếp theo mỗi dòng là 3 số L, R, K

// Constraints

// 1<=N<=10^6

// 1<=Q<=10^5

// 0<=L<=R<=N-1, 0<=A[i],K<=1000

// Output Format

// In ra mảng sau Q thao tác

// Sample Input 0

// 7 3
// 8 5 8 9 7 6 9 
// 0 5 0
// 0 5 0
// 1 5 1
// Sample Output 0

// 8 6 9 10 8 7 9 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
void slove(){
    cin >> n >> m;
    int a[n+1];
    int f[n+1];
    for (int i = 1;i<=n;i++){
        cin >> a[i];
    }
    f[1] = a[1];
    for (int i = 2;i<=n;i++){
        f[i] = a[i] - a[i-1];
    }
    while (m--){
        int x, y, k; cin >> x >> y >> k;
        x++, y++;
        f[x]+=k;
        f[y+1]-=k;
    }
    for (int i = 2;i<=n;i++){
        f[i] = f[i]+f[i-1];
    }
    for (int i = 1;i<=n;i++){
        cout << f[i] << " ";
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    slove();
    return 0;
}
