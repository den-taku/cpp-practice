// https://qiita.com/legohasiri/items/549569c38044f1afa083
// https://qiita.com/agate-pris/items/05948b7d33f3e88b8967
// https://osyo-manga.hatenadiary.org/entry/20101117/1289958984
// https://yohhoy.hatenablog.jp/entry/2012/12/15/120839
#include <iostream>
#include <array>
#include <string>
#include <vector>

class Hoge {
    public:
        std::string str;
        // constructor
        Hoge(std::string&& str) : str(str) {
            std::cout << str << ": constructor is called." << std::endl;
        }
        // copy constructor
        Hoge(const Hoge& obj) {
            std::cout << obj.str << ": copy constructor is called." << std::endl;
            this->str = obj.str;
        }
        // move constructor
        // Hoge(Hoge&& obj) {
        //     std::cout << obj.str << ": move constructor is called." << std::endl;
        //     this->str = std::move(obj.str);
        // }
        void print() { std::cout << this->str << std::endl; }
};

int32_t add(int32_t const a, int32_t const b) {
    return a + b;
}

void print(int32_t const& a) {
    std::cout << a << std::endl;
}

void print(std::string&& str) {
    std::cout << str << std::endl;
}

void twice_ref(int32_t& a) {
    std::cout << "call by reference." << std::endl;
    print(a);
    a *= 2;
    print(a);
}

bool twice(int32_t* a) {
    std::cout << "call by pointer." << std::endl;
    if (a == nullptr) {
        std::cout << "null" << std::endl;
        return false;
    }
    twice_ref(*a);
    return true;
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
        vec.push_back(i * i);
    }
    for (auto e: vec) {
        cout << e << ", ";
    }
    cout << endl;

    cout << add(234, 434) << endl;

    int32_t v = 4;
    twice(&v);
    cout << v << endl;
    twice(nullptr);

    twice_ref(v);
    cout << v << endl;

    int &&n = 10;
    print(n);

    print(string("String"));

    int32_t dead = 10;
    int32_t &&rvalue = std::move(dead);
    print(dead);
    print(rvalue);

    string dead_str = "fdaj`";
    string &&rvalue_str = std::move(dead_str);
    print(move(dead_str));
    print(move(rvalue_str));

    unique_ptr<string> p(new string("hoge"));
    auto q = move(p);
    assert(*q == string("hoge") && p == nullptr);

    vector<Hoge> v_hoge;
    v_hoge.reserve(10);
    cout << "push 1:" << endl;
    v_hoge.push_back(Hoge(string("first")));
    cout << "emplace 2:" << endl;
    v_hoge.emplace_back(Hoge(string("second")));
    cout << "emplace 3:" << endl;
    v_hoge.emplace_back(Hoge(string("third")));
    cout << "push 4:" << endl;
    v_hoge.emplace_back(string("forth"));
    cout << "emplace 5:" << endl;
    v_hoge.emplace_back(string("fifth"));

    for (auto& e: v_hoge) {
        e.print();
    }
}