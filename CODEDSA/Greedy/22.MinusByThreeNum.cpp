// Cho số nguyên dương N, nhiệm vụ của bạn là kiểm tra xem có thể viết N = a * b * c hay không, trong đó a, b, c là 3 số nguyên dương lớn hơn hoặc bằng 2 khác nhau.

// Input Format

// Dòng duy nhất chứa số nguyên dương N

// Constraints

// 2<=N<=10^9

// Output Format

// In ra YES nếu có thể biểu diễn N dưới dạng tích của 3 số, ngược lại in ra NO

// Sample Input 0

// 11
// Sample Output 0

// NO
// Sample Input 1

// 24
// Sample Output 1

// YES
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<int> vt;
    for (int i=2;i<=sqrt(n);i++){
        if (n%i==0){
            int cnt = 0;
            while (n%i==0){
                cnt++;
                n/=i;
            }
            vt.push_back(cnt);
        }
    }
    ll res = 1;
    for (int x : vt){
        res *= (x+1);
    }
    if (res >= 3) cout << "YES";
    else cout << "NO";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
