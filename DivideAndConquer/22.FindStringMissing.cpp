// Cho xâu F được định nghĩa như sau : F(1) = "28tech", F(2) = "C++", F(3) = "DSA JAVA". F(N) = F(N - 3) + " " + F(N -2) + " " + F(N - 1). Vì thế F(4) = "28tech C++ DSA JAVA", F(5) = "C++ DSA JAVA 28tech C++ DSA JAVA". Nhiệm vụ của bạn là tìm từ thứ K trong xâu F(N), dữ liệu đảm bảo xâu F(N) có từ thứ K

// Input Format

// Dòng 1 là T : số bộ test

// T dòng tiếp theo mỗi dòng gồm 2 số N, K

// Constraints

// 1<=T<=100

// 1<=N<=60

// 1<=K<=10^16

// Output Format

// In ra kết quả của mỗi test trên từng dòng

// Sample Input 0

// 10
// 3 2
// 6 2
// 10 24
// 4 2
// 5 4
// 6 12
// 7 22
// 8 1
// 7 18
// 8 14
// Sample Output 0

// JAVA
// JAVA
// JAVA
// C++
// 28tech
// DSA
// C++
// C++
// C++
// C++

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string F[4] = {"", "28tech", "C++", "DSA JAVA"};
ll Fn[100];
void init(){
    Fn[1] = 1, Fn[2] = 1, Fn[3] = 2; 
    for (int i = 4;i<=60;i++){
        Fn[i] = Fn[i - 3] + Fn[i-2] + Fn[i-1];
    }
}
vector<string> split(string s){
    vector<string> res; 
    stringstream ss(s);
    string word;
    while (ss >> word){
        res.push_back(word);
    }
    return res;
}
string DAC(int n, ll k){
    if (n <= 3) return split(F[n])[k-1];
    if (k <= Fn[n-3]) return DAC(n - 3, k);
    if (k <= Fn[n-3] + Fn[n-2]) return DAC(n - 2, k - Fn[n - 3]);
    return DAC(n-1, k - Fn[n - 2] - Fn[n - 3]);
}
int main() {
    int n; cin >> n;
    init();
    while (n--){
        int x; ll y; cin >> x >> y;
        cout << DAC(x, y) << endl;
    }
}
