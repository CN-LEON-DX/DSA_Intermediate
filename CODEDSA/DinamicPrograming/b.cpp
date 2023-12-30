// Đối với Trường, một tháng được coi là ẩm ướt khi trong tháng đó tồn tại ít nhất một chuỗi ngày liên tiếp (độ dài ít nhất K ngày liên tiếp), mà trong chuỗi ngày liên tiếp được chọn đó, ngày nào cũng phải có mưa, và tổng lượng mưa của chuỗi ngày được chọn phải lớn hơn hoặc bằng S. Nếu không phải là một tháng ẩm ướt thì nó là tháng khô ráo.

// Trường cung cấp cho bạn thống kê lượng mưa cho bạn, bạn hãy giúp anh ấy trả lời tháng đó là tháng khô ráo hay ẩm ướt.

// Đầu vào
// Dòng đầu tiên chứa số nguyên T (1<=T<=1000) - số trường hợp thử nghiệm.
// Trong T dòng tiếp theo:

// Dòng thứ nhất chứa 3 số nguyên N, K, S (28<=N<=31, 0<=K<=N, K<=S<=109). Trong đó N là số ngày trong tháng, K là độ dài ít nhất của chuỗi ngày cần được chọn, S tổng số lượng mưa ít nhất cần đạt)
// Dòng thứ hai chứa N số nguyên a1, a2,…, aN (0<=ai<=109) – lượng mưa ngày thứ i trong tháng.
// Đầu ra
// In ra T dòng đáp án, nếu tháng đó là khô ráo in ra KHO_RAO, nếu tháng đó là ẩm ướt in ra AM_UOT.

// Input
// Copy
// 10
// 29 13 33
// 12 10 35 0 0 0 4 12 32 48 0 34 8 43 0 0 25 10 36 50 0 2 48 48 0 0 17 5 15
// 28 25 49
// 0 28 5 40 42 19 5 34 10 6 5 28 31 24 28 0 35 40 45 29 5 16 29 30 48 26 0 0
// 28 10 29
// 7 0 22 20 18 0 6 0 18 23 49 28 39 25 39 40 13 1 34 8 46 0 14 0 16 26 23 34
// 28 4 32
// 0 0 20 6 39 16 48 0 14 9 0 20 5 3 5 39 0 12 14 21 0 0 16 29 6 0 49 0
// 30 11 16
// 6 13 39 19 23 15 40 50 0 17 22 4 0 2 0 0 14 23 4 32 36 13 7 0 27 5 7 24 11 36
// 30 19 22
// 0 27 31 29 21 38 28 0 32 4 42 34 20 11 29 12 4 8 6 19 0 11 0 0 15 37 6 21 4 47
// 30 14 48
// 43 29 0 37 14 29 0 43 5 25 26 37 46 49 29 33 44 5 40 0 0 25 26 42 27 41 18 20 0 31
// 29 23 37
// 0 20 43 26 0 0 45 48 26 39 0 24 16 0 49 29 1 31 45 1 28 4 8 23 19 31 43 42 14
// 31 0 0
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 31 18 34
// 39 22 46 49 24 47 18 20 0 30 27 42 0 25 0 38 6 0 22 15 50 16 4 40 0 5 0 0 35 0 50
// Output

// Copy
// KHO_RAO
// KHO_RAO
// AM_UOT
// AM_UOT
// KHO_RAO
// KHO_RAO
// KHO_RAO
// KHO_RAO
// AM_UOT
// KHO_RAO