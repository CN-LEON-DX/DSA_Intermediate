// Cho số tự nhiên N, bạn được cung cấp một hoán vị của N phần tử từ 1 tới N. Nhiệm vụ của bạn là sinh ra hoán vị kế tiếp của hoán vị được cho, nếu hoán vị được cho là hoán vị cuối cùng thì yêu cầu in ra hoán vị đầu tiên.

// Input Format

// Dòng đầu tiên là số tự nhiên N. Dòng thứ 2 là các số tự nhiên trong hoán vị hiện tại.

// Constraints

// 1<=N<=1000;

// Output Format

// In ra hoán vị kế tiếp trên một dòng.

// Sample Input 0

// 6
// 3 1 5 6 2 4 
// Sample Output 0

// 3 1 5 6 4 2 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int S[1001];
int check = 0;
void sinh(){
    int i = n-1;
    while (i>=1 && S[i] > S[i+1]) --i;
    if (i==0) check = 1;
    else{
        int j = n;
        while (S[i] > S[j]) j--;
        swap(S[i], S[j]);
        reverse(S+i+1, S+n+1);
    }
}
int main() {
    cin >> n;
    for (int i = 1;i<=n;i++) cin >> S[i];
    sinh();
    if (check){
        for (int i = 1;i<=n;i++) cout << i << " ";
    }else{
        for (int i = 1;i<=n;i++) cout << S[i] << " ";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}