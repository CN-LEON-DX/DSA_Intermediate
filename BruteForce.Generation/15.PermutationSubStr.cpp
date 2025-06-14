// Cho một xâu kí tự S chỉ bao gồm các kí tự , hãy in ra các hoán vị của các kí tự khác nhau trong S theo thứ tự từ điển tăng dần.

// Input Format

// 1 dòng chứa xâu S

// Constraints

// 1<=len(S)<=10;

// Output Format

// In ra các hoán vị của xâu S

// Sample Input 0

// lqk
// Sample Output 0

// klq
// kql
// lkq
// lqk
// qkl
// qlk

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char S[11];
int check = 0;
int n;
void sinh(){
    int i = n - 1;
    while (i>=1 && S[i] > S[i+1]) --i;
    if (i==0) check = 1;
    else{
        int j = n;
        while (S[i] > S[j]) --j;
        swap(S[i], S[j]);
        reverse(S+i+1, S+n+1);
    }
}
int main() {
    string s; cin >> s;
    set<char> se(s.begin(), s.end());
    n = se.size();
    int t = 1;
    for (char x : se){
        S[t] = x;
        ++t;
    }
    sort(S+1, S+n+1);
    while (!check){
        for (int i =1;i<=n;i++){
            cout << S[i];
        }
        cout << endl;
        sinh();
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}