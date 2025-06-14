// Có một danh sách vị trí được đánh số từ 1, 2, 3,... tới +oo. Các thành viên của câu lạc bộ Giải Thuật Lập Trình đang ở N vị trí lần lượt là p1, p2,…, pN. Khoảng cách từ vị trí x, đến vị trí y là |x-y|. Tất cả thành viên câu lạc bộ Giải Thuật Lập Trình định gặp nhau tại cùng một vị trí mà ở đó tổng khoảng cách phải di chuyển của tất cả thành viên là ít nhất có thể.

// Hãy giúp câu lạc bộ tính toán các giá trị sau:

// Số lượng những vị trí gặp nhau thoả mãn tổng khoảng cách di chuyển ít nhất.
// Liệt kê ra những vị trí đó
// Đầu vào
// Dòng đầu tiên chứa số nguyên T (1<=T<=1000) - số trường hợp thử nghiệm.

// Trong T dòng tiếp theo:

// Dòng thứ nhất chứa số nguyên N (1<=N<=105) – số lượng thành viên của câu lạc bộ.
// Dòng thứ hai chứa N số nguyên p1, p2,…, pN (0<=pi<=1e9) – vị trí của thành viên thứ i.
// Đảm bảo rằng tổng N các trường hợp thử nghiệm không quá 105

// Đầu ra
// Đối với mỗi dòng thử nghiệm in ra đáp án:

// Số lượng những vị trí gặp nhau thoả mãn tổng khoảng cách di chuyển ít nhất, gọi là K
// Liệt kê ra min(K, 10) vị trí đầu tiên sắp xếp theo thứ tự tăng dần.
// Input
// Copy
// 10
// 9
// 39 5 37 18 25 50 34 13 21 
// 1
// 38 
// 7
// 46 37 9 27 4 22 42 
// 10
// 47 1 10 22 33 3 38 14 30 46 
// 7
// 34 17 32 7 35 23 23 
// 8
// 19 37 1 41 34 35 21 11 
// 7
// 5 26 50 41 17 18 49 
// 7
// 33 41 14 11 25 13 26 
// 9
// 30 11 26 10 8 11 22 15 8 
// 8
// 13 2 26 33 3 12 11 32 
// Output

// Copy
// 1
// 25
// 1
// 38
// 1
// 27
// 9
// 22 23 24 25 26 27 28 29 30 
// 1
// 23
// 14
// 21 22 23 24 25 26 27 28 29 30 
// 1
// 26
// 1
// 25
// 1
// 11
// 2
// 12 13 