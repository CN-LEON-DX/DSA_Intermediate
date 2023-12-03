// Tìm ước số nguyên tố lớn nhất của một số nguyên dương.

// Input Format

// Dòng đầu tiên là số lượng test case T; T dòng tiếp theo mỗi dòng là một số nguyên dương N

// Constraints

// 1≤T≤500; 2≤N≤10000000

// Output Format

// Ước số nguyên tố lớn nhất của n in ra mỗi test case trên 1 dòng

// Sample Input 0

// 2
// 10
// 17
// Sample Output 0

// 5
// 17

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void solve(){
    int n; cin >> n;
    while (n--){
        int a; cin >> a;
        int k = 1;
        for (int i = 2;i*i<=a;i++){
            if (a%i==0) k = max(k, i);
            while (a%i==0){
                a/=i;
            }
        }
        k = max(k, a);
        cout << k << endl;
    }
}
int main() {
    solve();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}