// Một xâu ký tự số chỉ bao gồm các chữ số 6 và 8 sẽ được gọi là “phát lộc” nếu thỏa mãn các điều kiện sau: Chữ số đầu tiên là chữ số 8, chữ số cuối cùng là chữ số 6. Không có 2 chữ số 8 nào ở cạnh nhau. Không có nhiều hơn 3 chữ số 6 ở cạnh nhau. Viết chương trình liệt kê các xâu ký tự phát lộc độ dài N theo thứ tự tăng dần.

// Input Format

// Số nguyên dương N;

// Constraints

// 2<=N<=15;

// Output Format

// Các xâu lộc phát thỏa mãn điều kiện

// Sample Input 0

// 7
// Sample Output 0

// 8666866
// 8668666
// 8668686
// 8686686
// 8686866
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
bool check1(string s){
    for (int i = 0;i<n-1;i++){
        if (s[i]=='8' && s[i+1]=='8') return 0;
    }
    return 1;
}
bool check2(string s){
    // Khong co nhieu hon 3 so 6?
    int cnt = 0;
    int ok = 1;
    for (char x : s){
        if (x=='6'){
            cnt++;
            if (cnt>3) ok = 0;
        }else{
            cnt = 0;
        }
    }
    return ok;
}
int main() {
    cin >> n;
    vector<string> vt;
    for (int i = 0;i<(1<<n);i++){
        string temp = "";
        for (int j = 0;j<n;j++){
            if ((i&(1<<j))!=0){
                temp+="6";
            }else{
                temp+="8";
            }
        }
        if (temp[0]=='8' && temp[n-1]=='6') vt.push_back(temp);
    }
    vector<string> res;
    for (string x : vt){
        if (check1(x) && check2(x)) {
            res.push_back(x);
        }
    }
    sort(res.begin(), res.end());
    for (string x : res) cout << x << endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
