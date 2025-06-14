// Trong một buổi học toán, giáo viên viết 2 số nguyên, A và B, và yêu cầu Tèo thực hiện phép cộng. Tèo không bao giờ tính toán sai, nhưng thỉnh thoảng cậu ta chép các con số một cách không chính xác. Lỗi duy nhất của là ghi nhầm '5' thành '6' hoặc ngược lại. Cho hai số, A và B, tính tổng nhỏ nhất và lớn nhất mà Tèo có thể nhận được.

// Input Format

// 1 dòng duy nhất chứa 2 số A và B

// Constraints

// 1<=A<=B<=10^16

// Output Format

// In ra tổng lớn nhất và nhỏ nhất trên 1 dòng

// Sample Input 0

// 891 746
// Sample Output 0

// 1637 1636
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll doi(string s){
    for (char &x : s){
        if (x=='5') x = '6';
    }
    return stoll(s);
}
ll doimin(string s){
    for (char &x : s){
        if (x=='6') x = '5';
    }
    return stoll(s);
}

int main() {
    string s1, s2; cin >> s1 >> s2;
    cout << doi(s1) + doi(s2) << " " << doimin(s1) + doimin(s2) << endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
