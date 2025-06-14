// Cho một bảng HCN cỡ N hàng, M cột, mỗi ô trên HCN chứa 1 chữ cái in hoa hoặc chữ số. Một từ có thể được xây dựng từ các chữ cái của các ô liền kề theo thứ tự, trong đó các ô liền kề nằm cạnh nhau theo chiều ngang hoặc chiều dọc. Không được sử dụng cùng một ô chữ cái nhiều lần. Bạn hãy xác định xem có thể tạo thành từ S cho trước hay không ?
// Anhr minh hoa
// https://s3.amazonaws.com/hr-assets/0/1679467471-1d69faad6a-VD.png
// Input Format

// Dòng đầu tiên là N và M

// N dòng tiếp theo mô tả bảng HCN

// Dòng cuối cùng là từ S

// Constraints

// 1<=N,M<=5

// 1<=len(S)<=25

// Output Format

// In ra YES nếu có thể tạo được từ S, ngược lại in NO
// Sample Input 0

// 4 4
// ACAC
// 28B5
// 1TE5
// ABCH
// 28TECH
// Sample Output 0

// YES
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<string> board;
string S;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool found = false;

void DFS(int x, int y, int index, vector<vector<bool>>& visited) {
    if (index == S.size()) {
        found = true;
        return;
    }
    if (x < 0 || x >= N || y < 0 || y >= M || visited[x][y] || board[x][y] != S[index]) {
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        DFS(x + dx[i], y + dy[i], index + 1, visited);
    }
    visited[x][y] = false;
}

int main() {
    cin >> N >> M;
    board.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    cin >> S;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == S[0]) {
                DFS(i, j, 0, visited);
            }
        }
    }
    if (found) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}