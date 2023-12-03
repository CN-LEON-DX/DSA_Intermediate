// Một số được coi là đẹp nếu nó là số thuận nghịch và có ít nhất 3 ước số nguyên tố khác nhau. Viết chương trình in ra các số đẹp như vậy trong một đoạn giữa hai số nguyên cho trước

// Input Format

// 2 số a, b

// Constraints

// 1≤a≤b≤10^7

// Output Format

// In ra các số đẹp trong đoạn a, b. Trong trường hợp không tồn tại số đẹp nào thì in ra -1.

// Sample Input 0

// 1 1000
// Sample Output 0

// 66 222 252 282 414 434 444 474 494 525 555 585 595 606 616 636 646 666 696 777 828 858 868 888 969
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool checkTN(int n){
    int s = 0;
    int temp = n;
    while (n){
        s= s*10 + n%10;
        n/=10;
    }
    return s == temp;
}
bool check3(int n){
    int cnt = 0;
    for (int i = 2;i*i<=n;i++){
        if (n%i==0){
            cnt++;
            while (n%i==0){
                n/=i;
            }
        }
    }
    if (n>1) cnt++;
    return cnt >= 3;
}
int main() {
    int n, k; cin >> n >> k;
    vector<int> a;
    for (int i = n;i<=k;i++){
        if (checkTN(i)){
        a.push_back(i);
        }
    }
    int ok = 0;
    for (int x : a){
        if (check3(x)){
            cout << x << " ";
            ok = 1;
        }
    }
    if (!ok) cout << -1;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}