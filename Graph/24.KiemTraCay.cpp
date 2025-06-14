// Một đồ thị N đỉnh là một cây, nếu như nó có đúng N-1 cạnh và giữa 2 đỉnh bất kì, chỉ tồn tại duy nhất 1 đường đi giữa chúng. Cho một đồ thị vô hướng N đỉnh và M cạnh, hãy kiểm tra đồ thị đã cho có phải là một cây hay không?

// Input Format

// Dòng đầu tiên là số n, m tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

// Constraints

// 1<=n<=1000; 1<=m<=n*(n-1)/2;

// Output Format

// In ra 1 nếu đồ thị đã cho là cây, ngược lại in ra 0.

// Sample Input 0

// 6 5
// 4 3
// 2 1
// 6 5
// 5 4
// 3 2
// Sample Output 0

// 1
// Sample Input 1

// 6 4
// 6 3
// 3 2
// 4 2
// 6 4
// Sample Output 1

// 0