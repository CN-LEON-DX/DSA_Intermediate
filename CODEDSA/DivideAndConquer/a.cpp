Có N nhóm hạt ngũ cốc được đánh số từ 1 tới N mỗi nhóm sẽ có lượng hạt ngũ cốc là A[i] với 1<=i<=N, một con sóc đang ở vị trí nhóm hạt số 1. Nhiệm vụ của nó là tới được nhóm hạt thứ N, chi phí mỗi lần di chuyển từ nhóm hạt x sang nhóm hạt y là abs(A[x] - A[y]), mỗi lần di chuyển con sóc chỉ có thể di chuyển từ nhóm hạt i sang nhóm hạt i + 1 hoặc i + 2,... i + K. Nhiệm vụ của bạn là tính số lượng ngũ cốc tối thiểu mà con sóc này phải tiêu tốn để có thể đi đến nhóm hạt thứ N

Input Format

Dòng 1 N, K

Dòng 2 là N số là số hạt ngũ cốc của mỗi nhóm từ 1 tới N

Constraints

1<=N<=10^6

1<=K<=100

1<=A[i]<=10^9

Output Format

In ra số lượng ngũ cốc mà sóc đã mất làm chi phí di chuyển

Sample Input 0

5 3
5 1 1 4 7 
Sample Output 0

4