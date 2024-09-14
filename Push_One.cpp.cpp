#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // Để định dạng số thập phân

using namespace std;

// Định nghĩa cấu trúc Học Sinh
struct HocSinh {
    string maHS;
    string ten;
    string diaChi;
    double diem1, diem2, diem3;
    double diemTrungBinh;

    // Hàm tính điểm trung bình
    void tinhDiemTrungBinh() {
        diemTrungBinh = (diem1 + diem2 + diem3) / 3;
    }
};

// Hàm so sánh để sắp xếp học sinh theo điểm trung bình giảm dần
bool compareHocSinh(const HocSinh &a, const HocSinh &b) {
    return a.diemTrungBinh > b.diemTrungBinh;
}

int main() {
    vector<HocSinh> danhSachHS(2); // Tạo danh sách học sinh với 2 học sinh

    // Nhập thông tin học sinh
    for (int i = 0; i < 2; i++) {
        cin >> danhSachHS[i].maHS;
        cin.ignore(); // Bỏ qua ký tự xuống dòng sau mã học sinh
        getline(cin, danhSachHS[i].ten);
        getline(cin, danhSachHS[i].diaChi);
        cin >> danhSachHS[i].diem1 >> danhSachHS[i].diem2 >> danhSachHS[i].diem3;

        // Tính điểm trung bình cho mỗi học sinh
        danhSachHS[i].tinhDiemTrungBinh();
    }

    // Sắp xếp danh sách học sinh theo điểm trung bình giảm dần
    sort(danhSachHS.begin(), danhSachHS.end(), compareHocSinh);

    // In thông tin học sinh đã sắp xếp
    for (const auto &hs : danhSachHS) {
        cout << hs.maHS << endl;
        cout << hs.ten << endl;
        cout << hs.diaChi << endl;
        cout << fixed << setprecision(1) << hs.diemTrungBinh << endl; // In điểm trung bình với 1 chữ số thập phân
    }

    return 0;
}
