#include "vectormap.hpp"

int main()
{
    VectorMap<int, char> map;
    map.insert(1, 'c');
    map[1] = 'e';           // replaces value under 1
    std::cout << map[1] << std::endl;    // prints 'e'
    try
    {
        map.at(2);
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::boolalpha <<map.isIntKey() << std::endl;

    VectorMap<std::string, char> map2;
    std::cout << std::boolalpha << map2.isIntKey() << std::endl;

    std::cout << std::boolalpha << VectorMap<int, char>::is_int_key << std::endl;
    std::cout << std::boolalpha << VectorMap<std::string, char>::is_int_key << std::endl;
    
}