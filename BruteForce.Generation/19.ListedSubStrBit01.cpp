// Nhiệm vụ của bạn là hãy liệt kê các xâu nhị phân thuận nghịch có độ dài n theo thứ tự từ điển.

// Input Format

// Dòng duy nhất chứa số nguyên dương n.

// Constraints

// 1<=n<=15;

// Output Format

// In ra các xâu thuận nghịch theo thứ tự từ điển

// Sample Input 0

// 4
// Sample Output 0

// 0000
// 0110
// 1001
// 1111

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int n;
int S[16];
int check = 0;
void init(){
    for (int i = 1;i<=n;i++) S[i] = 0;
}
void sinh(){
    int i = n;
    while (i>=1 && S[i]==1){
        S[i] = 0;
        --i;
    }
    if (i==0) check = 1;
    else{
        S[i]=1;
        for (int j = i+1;j<=n;j++){
            S[j] = 0;
        }
    }
}
bool checkvl(string temp){
    int l = 0, r = temp.size() - 1;
    while (l <= r){
        if (temp[l]!=temp[r]) return 0;
        l++;
        r--;
    }
    return 1;
}
int main() {
    cin >> n;
    while (!check){
        string temp = "";
        for (int i = 1;i<=n;i++) temp+=to_string(S[i]);
        if (checkvl(temp)) cout << temp << endl;
        sinh();
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
