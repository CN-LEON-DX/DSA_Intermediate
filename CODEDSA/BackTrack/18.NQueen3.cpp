// Vẫn là bài toán N quân hậu, nhiệm vụ của bạn là hãy in ra các cách xếp quân hậu trên bàn cờ cỡ N * N. Trong đó với mỗi ô trên bàn cờ có quân hậu chiếm chỗ sẽ đại diện là chữ Q, ngược lại ô trống sẽ là dấu '.'

// Input Format

// Dòng duy nhất chứa N là kích cỡ bàn cờ
// Constraints

// 1<=N<=10
// Output Format

// In ra các cách xếp quân hậu, mỗi cách xếp cách nhau một dòng trống
// Sample Input 0

// 4
// Sample Output 0

// .Q..
// ...Q
// Q...
// ..Q.

// ..Q.
// Q...
// ...Q
// .Q..

#include <cmath>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n;
int X[100];
int cot[100], xuoi[100], nguoc[100];
int cnt = 0;
multiset<pair<int, int>> se;
void Try(int i){
    for (int j = 1;j<=n;j++){
        if (cot[j]== 0 && xuoi[i-j+n]==0 && nguoc[i+j-1]==0){
            X[i] = j;
            se.insert({i, j});
            cot[j]=1;
            xuoi[i-j+n] = 1;
            nguoc[i+j-1] = 1;
            if (i==n){
                for (int u = 1;u<=n;u++){
                    for (int v = 1;v<=n;v++){
                        if (se.count({u, v})>0){
                            cout << "Q";
                        }else{
                            cout << ".";
                        }
                    }
                    cout << endl;
                }
                cout << endl;
                ++cnt;
            }else{
                Try(i+1);
            }
            se.erase({i, j});
            // backtrack
            cot[j]=0;
            xuoi[i-j+n] = 0;
            nguoc[i+j-1] = 0;
        }
    }
}

int main() {
    cin >> n;
    Try(1);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
