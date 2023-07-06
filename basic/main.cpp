// https://qiita.com/legohasiri/items/549569c38044f1afa083
#include <iostream>
#include <array>
#include <string>
#include <vector>

int32_t add(int32_t a, int32_t b) {
    return a + b;
}

int main() {
    using namespace std;
    std::cout << "Hello, world!" << std::endl;

    constexpr auto e = 2.71;
    cout << e << endl;

    array<int32_t, 6> ary = { 0, 1, 2, 3, 4, 5 };
    for (auto e: ary) {
        cout << e << ", ";
    }
    cout << endl;
    for (int i = 0; i < ary.size(); i++) {
        cout << ary.at(i) << ", ";
    }
    cout << endl;

    string str = "Hello, world!";
    cout << str << endl;

    vector<int32_t> vec;
    for (int i = 0; i < 10; i++) {
        int32_t n;
        cin >> n;
        vec.push_back(n);
    }
    for (auto e: vec) {
        cout << e << ", ";
    }
    cout << endl;

    cout << add(234, 434) << endl;
}