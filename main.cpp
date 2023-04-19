#include <iostream>
#include <vector>

using namespace std;

void TestVector1() {
    vector<int> v1;
    vector<int> v2(10, 5);

    int array[] = {1, 2, 3, 4, 5, 6};
    vector<int> v3(array, array + (sizeof(array) / sizeof(array[0])));

    vector<int> v4(v3);

    //c++11
    vector<int> v5{1, 2, 3, 4, 5, 6};

    for (auto e: v2)
        cout << e << " ";
    cout << endl;

    for (size_t i = 0; i < v4.size(); ++i)
        cout << v4[i] << " ";
    cout << endl;
    //正向迭代器
    auto it = v5.begin();
    while (it != v5.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    //反向迭代器
    vector<int>::reverse_iterator rit = v5.rbegin();
    while (rit != v5.rend()) {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;
}

void TestVector2() {
    vector<int> v{1, 2, 3, 4, 5};

    v.resize(10, 6);
    v.resize(20, 7);
    v.resize(40, 8);

    v.resize(30);
    v.resize(20);
    v.resize(10);
}

void TestVector3() {
    vector<int> v{1, 2, 3, 4, 5};

    v.reserve(10);
    v.reserve(20);
    v.reserve(30);

    v.reserve(20);
    v.reserve(10);
    v.reserve(2);
}

void TestVector4() {
    vector<int> v{1, 2, 3, 4, 5};
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << v[0] << endl;
    cout << v.at(0) << endl;

    v.clear();//只是将有效元素销毁，并不会缩小空间大小
    if (v.empty())
        cout << "v is empty" << endl;
    else
        cout << "v is not empty" << endl;
}

void TestVector5() {
    vector<int> v;
    size_t sz = v.capacity();

    for (size_t i = 0; i < 100; ++i) {
        v.push_back(i);
        if (sz != v.capacity()) {
            sz = v.capacity();
            cout << sz << endl;
        }
    }
}

void TestVector6() {
    vector<int> v1{1, 2, 3};
    vector<int> v2{4, 5, 6};

    v2.insert(v2.begin(), 0);
    vector<int>::iterator pos = find(v2.begin(), v2.end(), 4);
    if (pos != v2.end()) {
        v2.insert(pos, v1.begin(), v1.end());
    }

    int array[] = {8, 9, 10};
    v1.insert(v1.end(), array, array + sizeof(array) / sizeof(array[0]));
    v2.insert(v2.begin(), 10, 8);

    v1.erase(v1.begin());
    v1.erase(v1.begin(), v1.begin() + 3);
    v1.erase(v1.begin(), v1.end());
}

int main() {
    //TestVector1();
    //TestVector2();
    //TestVector3();
    //TestVector4();
    //TestVector5();
    TestVector6();

    return 0;
}
