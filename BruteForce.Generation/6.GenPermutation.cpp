// Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các hoán vị của các số từ 1 tới N theo thứ tự ngược.

// Input Format

// Dòng duy nhất chứa số nguyên dương N.

// Constraints

// 1<=N<=10;

// Output Format

// In ra các hoán vị của N phần tử theo thứ tự ngược

// Sample Input 0

// 3
// Sample Output 0

// 321
// 312
// 231
// 213
// 132
// 123
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int n;
int S[100];
int check = 0;
void init(){
    for (int i = 1;i<=n;i++) S[i] = i;
}
void sinh(){
    int i = n - 1;
    while (i>=1 && S[i] > S[i+1]) --i;
    if (i==0) check = 1;
    else {
        int j = n;
        while (S[i] > S[j]) --j;
        swap(S[i], S[j]);
        reverse(S+i+1, S+n+1);
    }
}
int main() {
    cin >> n;
    init();
    vector<string> vt;
    while (!check){
        string s = "";
        for (int i = 1;i<=n;i++) s+=to_string(S[i]);
        vt.push_back(s);
        sinh();
    }
    for (int i = vt.size()-1;i>=0;i--){
        cout << vt[i] << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}