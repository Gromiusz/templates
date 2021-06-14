#include <iostream>
#include "vectorMap.hpp"

class K {
public:
    K(int k) {}
};

// primary template
template <typename T1, typename T2, typename T3>
class A {};

// partial specialization with T1 = int
template <typename T2, typename T3>
class A<int, T2, T3> {};

// partial specialization with T1 = int and T2 = double
template <typename T3>
class A<int, double, T3> {};

// partial specialization with T1 = int and T3 = char
template <typename T2>
class A<int, T2, char> {};

// full specialization with T1 = T2 = double and T3 = int
template <>
class A<double, double, int> {};

// template<typename To, typename From>
// To convert(From f) {}

int main()
{
    A<int, int, int> a;
    A<double, double, int> b;
    A<int, int, char> c;
    // auto a = convert(3.14);
    // auto b = convert<int>(3.14);
    // auto c = convert<int, double>(3.14);
    // int(*ptr)(float) = convert;
    // int(*ptr2)(float) = convert<int, float>;

    VectorMap<int, char> ic;
    ic.insert(4, 'a');
    std::cout << ic[4] << '\n';
    ic[4] = 'b';
    std::cout << ic[4] << '\n';
    std::cout << ic.at(4) << '\n';
    // std::cout << ic.at(5) << '\n';

    // VectorMap<int, K> kc;

    VectorMap<int, char>::key_type v1 = 10;

    std::cout << ic.is_int_key << '\n';
    std::cout << VectorMap<char, int>::is_int_key << '\n';

    std::cout << "is_int_key_v<VectorMap<int, char>>: " << is_int_key_v<VectorMap<int, char>> << '\n';
    std::cout << "is_int_key_v<decltype(ic)>: " << is_int_key_v<decltype(ic)> << '\n';
    std::cout << "is_int_key_v<VectorMap<char, char>>: " << is_int_key_v<VectorMap<char, char>> << '\n';

    VectorMap<bool, char> bc;
    bc.insert(true, 'a');
    std::cout << bc[true] << '\n';
    bc[true] = 'b';
    std::cout << bc[true] << '\n';
    std::cout << bc.at(true) << '\n';

    std::cout << bc.is_int_key << '\n';
    std::cout << VectorMap<bool, int>::is_int_key << '\n';

    return 0;
}
