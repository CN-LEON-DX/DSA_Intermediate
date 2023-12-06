// Bạn được cung cấp một số nguyên x. Bạn có thể biểu diễn x bằng cách tổng của các số trong các số 11,111,1111,11111,… ( Các số mà bản thân nó chỉ chứa các chữ số 1)?(Bạn có thể sử dụng bất kỳ số nào trong số chúng bất kỳ số lần nào). Ví dụ, 33 = 11 + 11 + 11 144 = 111 + 11 + 11 + 11

// Input Format

// Số nguyên dương N

// Constraints

// 1≤n≤10^9

// Output Format

// Nếu bạn có thể tạo x bởi các số 11,111,1111,...., hãy xuất "YES" (không có dấu ngoặc kép). Nếu không, xuất "NO".

// Sample Input 0

// 144
// Sample Output 0

// YES
// Sample Input 1

// 69
// Sample Output 1

// NO

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    while (n>=11){
        int time = 0;
        ll temp = n;
        while(temp){
            time++;
            temp/=10;
        }
        string t = "";
        while (time--){
            t+="1";
        }
        if (n>=stoll(t)){
             n-= stoll(t); 
            cout << stoll(t) << endl;
        }
        else{
            n-= stoll(t)/10;
            cout << stoll(t)/10 << endl;
        }
    }
    if (n==0){
        cout << "YES";
    }else{
        cout << "NO";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
#include <string>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    while (n >= 11) {
        string s = "1";
        while (stoll(s) < n) {
            if (stoll(s) > n) break;
            s += "1";
        }
        if (s != "1" && stoll(s) <= n) n -= stoll(s);
    }

    cout << n << endl;
    if (n == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
