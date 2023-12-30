// Cho xâu nhị phân S, hãy in ra xâu nhị phân kế tiếp của S. Trong trường hợp S là xâu nhị phân cuối cùng thì in ra xâu nhị phân đầu tiên.

// Input Format

// 1 dòng duy nhất chưa xâu nhị phân S

// Constraints

// 1<=len(S)<=1000;

// Output Format

// In ra xâu nhị phân kế tiếp.
// Sample Input 0
// 1110010
// Sample Output 0
// 1110011
// Sample Input 1
// 11111
// Sample Output 1
// 00000
#include <bits/stdc++.h>
using namespace std;
int S[1001];
int n = 0;
int check = 0;
void sinh(){
    int i = n;
    while (i>=1 && S[i]==1){
        S[i] = 0;
        i--;
    }
    if (i==0) check = 1;
    else {
        S[i] = 1;
    }
}
int main(){
    string s; cin >> s;
    for (char x : s){
        n++;
        S[n] = x-'0';
    }
    sinh();
    if (check){
        while (n--){
            cout << 0;
        }
    }else{
        for (int i = 1;i<=n;i++){
            cout << S[i];
        }
    }
    return 0;
}