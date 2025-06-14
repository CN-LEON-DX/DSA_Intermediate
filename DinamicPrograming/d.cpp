// Có một danh sách vị trí được đánh số từ 1 tới +oo. Các thành viên của câu lạc bộ Giải Thuật Lập Trình đang ở N vị trí lần lượt là p1, p2,…, pN. Khoảng cách từ vị trí x, đến vị trí y là |x-y| mét. Thời gian di chuyển từ vị trí x, đến vị trí y là |x-y| giây. Tất cả thành viên câu lạc bộ Giải Thuật Lập Trình định gặp nhau tại cùng một vị trí để cùng nhau đi ăn. Tất cả các thành viên đều xuất phát cùng lúc và đi đến điểm đến vị trí gặp nhau gọi là Z. Nếu ai đó đến Z trước, họ sẽ chờ những người còn lại. Câu lạc bộ muốn tập trung mọi người nhanh nhất có thể.

// Bạn hãy giúp câu lạc bộ tính toán các giá trị sau:

// Thời gian tập trung ít nhất.
// Số lượng những vị trí gặp nhau thoả mãn.
// Liệt kê ra những vị trí đó.
// Đầu vào
// Dòng đầu tiên chứa số nguyên T (1<=T<=1000) - số trường hợp thử nghiệm.

// Trong T dòng tiếp theo:

// Dòng thứ nhất chứa số nguyên N (1<=N<=105) – số lượng thành viên của câu lạc bộ.
// Dòng thứ hai chứa N số nguyên p1, p2,…, pN (0<=pi<=1e9) – vị trí của thành viên thứ i.
// Đảm bảo rằng tổng N các trường hợp thử nghiệm không quá 105

// Đầu ra
// Đối với mỗi dòng thử nghiệm in ra đáp án:

// Thời gian tập trung ít nhất.
// Số lượng những vị trí gặp nhau thoả mãn, gọi là K
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
// 23
// 2
// 27 28 
// 0
// 1
// 38 
// 21
// 1
// 25 
// 23
// 1
// 24 
// 14
// 1
// 21 
// 20
// 1
// 21 
// 23
// 2
// 27 28 
// 15
// 1
// 26 
// 11
// 1
// 19 
// 16
// 2
// 17 18 