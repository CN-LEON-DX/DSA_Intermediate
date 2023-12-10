// Với mỗi số nguyên dương N, số M được coi là đặc biệt của N nếu M được tạo ra bằng tổng các luỹ thừa không âm khác nhau của N. Ví dụ N=4 thì M=17 là số đặc biệt vì 4^0+4^2=17 Viết chương trình nhập số N và số K. Sau đó in ra số đặc biệt thứ K của N nếu sắp xếp các số đặc biệt của N theo thứ tự tăng dần. Kết quả có thể rất lớn, hãy in ra theo modulo (10^9)+7.

// Input Format

// 1 dòng chứa 2 số N và K

// Constraints

// 2<=N<=10^9; 1<=K<=10^9

// Output Format

// Với mỗi bộ test in ra số đặc biệt thứ K của N theo modulo 10^9+7.

// Sample Input 0

// 3 4
// Sample Output 0

// 9
// Explanation 0

// Với N =3 thì dãy số đặc biệt là 1, 3, 4, 9, 10....

// Sample Input 1

// 105 564
// Sample Output 1

// 3595374
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007
int main(){
    int n, k; cin >> n >> k;
    string s;
    int _k = k;
    while(_k){
        s += char(_k%2+'0');
        _k/=2;
    }
    ll res = 0;
    ll p = 1;
    for (int i = 0;i<s.size();i++){
        if (s[i]=='1'){
            res+=p;
        }
        p = (p*n)%MOD;
    }
    cout << res%MOD << endl;
    return 0;
}