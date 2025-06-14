#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int n, m, s; vector<int> a[1001];
bool visited[1001];
void dfs(int u){
    visited[u] = true;
    cout << u << ' ';
    for (int v : a[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}
int main(){
    memset(visited, false, sizeof(visited));
    cin >> n >> m >> s;
    while (m--){
        int x, y; cin >> x >> y;
        a[x].push_back(y);
    }
    for (int i = 1; i<= n;i++){
        sort(a[i].begin(), a[i].end());
    }
    dfs(s);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

Cho đồ thị có hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy thực hiện in ra danh sách các đỉnh được duyệt theo thuật toán DFS(s).

Input Format

Dòng đầu tiên là 2 số n và m và s, tương ứng với số lượng đỉnh, cạnh của đồ thị và đỉnh bắt đầu duyệt. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Constraints

1<=s<=n<=1000; 1<=m<=n*(n-1)/2;

Output Format

In ra các đỉnh được duyệt theo thuật toán DFS(s). Chú ý trong quá trình mở rộng các đỉnh của thuật toán DFS luôn lựa chọn duyệt các đỉnh có thứ tự nhỏ hơn trước.

Sample Input 0

5 10 4
5 1
4 5
4 2
4 3
1 5
3 5
5 3
3 1
1 4
5 2
Sample Output 0

4 2 3 1 5 