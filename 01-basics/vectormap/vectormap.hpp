#include <vector>
#include <stdexcept>
#include <type_traits>
#include <algorithm>

template <typename KeyType, typename ValueType>
class VectorMap
{
    static_assert(std::is_constructible<ValueType>::value, "ValueType have to have default constructor");
    std::vector<KeyType> keys;
    std::vector<ValueType> values;

public:
    void insert(KeyType key, ValueType value);
    ValueType &operator[](KeyType key);
    ValueType &at(KeyType key);
};

template <typename KeyType, typename ValueType>
void VectorMap<KeyType, ValueType>::insert(KeyType key, ValueType value)
{
    keys.emplace_back(key);
    values.emplace_back(value);
}

template <typename KeyType, typename ValueType>
ValueType& VectorMap<KeyType, ValueType>::operator[](KeyType key)
{
    auto it = std::find(std::begin(keys), std::end(keys), key);
    if(it == std::end(keys))
    {
        keys.emplace_back(key);
        values.emplace_back(ValueType{});
        return values.back();
    }
    auto dist = std::distance(std::begin(keys), it);
    return values[dist];
}

template <typename KeyType, typename ValueType>
ValueType& VectorMap<KeyType, ValueType>::at(KeyType key)
{
    if (key >= values.size())
    {
        throw std::out_of_range("key is out of range");
    }
    return values[key];
}