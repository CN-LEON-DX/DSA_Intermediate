// Cho số nguyên dương N, bạn hãy in ra các cách biểu diễn N dưới dạng tổng của các số tự nhiên không vượt quá N.

// Input Format

// Số nguyên dương N

// Constraints

// 1<=N<=20;

// Output Format

// Dòng đầu tiên in ra số lượng cách biểu diễn. Các dòng tiếp theo in ra cách biểu diễn được liệt kê theo thứ tự từ từ điển giảm dần.

// Sample Input 0

// 5
// Sample Output 0

// 7
// 5
// 4+1
// 3+2
// 3+1+1
// 2+2+1
// 2+1+1+1
// 1+1+1+1+1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, S[21];
int check = 0;
int cnt = 0;
void init(){
    ++cnt;
    S[1] = n;
}
void sinh(){
    int i = cnt;
    while (i>=1 && S[i]==1){
        --i;
    }
    if (i==0) check = 1;
    else{
        S[i]--;
        int d = cnt - i + 1;
        cnt = i;
        int p = d/S[i], r = d%S[i];
        for (int j = 1;j<=p;j++) {
            ++cnt;
            S[cnt] = S[i];
        }
        if (r){
            ++cnt;
            S[cnt] = r;
        }
    }
}
int main() {
    cin >> n;
    init();
    vector<string> vt;
    while (!check){
        string temp = "";
        for (int i = 1;i<=cnt;i++){
            if(cnt==1) {
                temp+=to_string(n);
                break;
            }
            else{
                if (i==cnt){
                    temp+=to_string(S[i]);
                }else{
                    temp+=to_string(S[i])+"+";
                }
            }
        }
        vt.push_back(temp);
        sinh();
    }
    cout << vt.size() << endl;
    for (string x : vt){
        cout << x << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

