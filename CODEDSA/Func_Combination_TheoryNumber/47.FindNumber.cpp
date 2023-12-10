// Bạn được cung cấp một mảng gồm n số nguyên dương. Nhiệm vụ của bạn là tìm hai số nguyên sao cho ước số chung lớn nhất của chúng càng lớn càng tốt

// Input Format

// Dòng nhập đầu tiên có số nguyên n: kích thước của mảng. Dòng thứ hai có n số nguyên x1, x2,…, xn: nội dung của mảng.

// Constraints

// 2≤n≤10^6; 1≤xi≤10^6

// Output Format

// In ước số chung lớn nhất lớn nhất.

// Sample Input 0

// 5
// 3 14 15 7 9
// Sample Output 0

// 7
// Explanation 0

// 2 số 14 và 7 có ước chung lớn nhất là 7, là ước chung lớn nhất của 2 số trong mảng
// 5
// 3 14 15 7 9
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 1000001

int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> freq(MAX, 0);
    ll maxNum = 0;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
        maxNum = max(maxNum, arr[i]);
    }
    //hien thi mang freq
    for (int i=0;i<MAX;i++){
        if (freq[i]!=0) cout << i << " " << freq[i] << endl;
    }

    ll res = 1;
    for(ll i = maxNum; i >= 1; i--) {
        ll j = i;
        ll counter = 0;
        cout << "j = " << j << endl;
        cout << "counter = " << counter << endl; 
        while(j <= maxNum) {
            cout << "j = " << j << endl;
            if(freq[j] >= 2) {
                res = max(res, j);
                cout << "res = " << res << endl;
                break;
            } else if(freq[j] == 1) {
                cout << "counter++" << endl;
                counter++;
            }
            if(counter == 2) {
                res = max(res, i);
                cout << "res = " << res << endl;
                break;
            }
            j += i;
        }
    }

    cout << res << endl;
    return 0;
}

// CÁCH 1 KHÓ HIỂU NÊN DÙNG CÁCH 2
#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int n){
    int maxe = 0;
    for (int i=0;i<n;i++){
        maxe = max(maxe, a[i]);
    }
    int dp[maxe+1] = {0};
    for (int i = 0;i<n;i++){
        dp[a[i]]++;
        for (int j = 2;j*j<=a[i];j++){
            if (a[i]%j==0){
                dp[j]++;
                if (j*j != a[i]){
                    dp[a[i]/j]++;
                }
            }
        }
    }
    
    for (int i = maxe;i>=1;i--){
        if (dp[i]>1){
             return i;
        }
    }
    return -1;
}

int main(){
    int n; cin >> n;
    int a[n]; 
    for (int i = 0;i<n;i++){
        cin >> a[i];
    }
    cout << solve(a, n);
    return 0;
}