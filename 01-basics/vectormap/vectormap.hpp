#include <vector>
#include <stdexcept>
#include <type_traits>
#include <algorithm>
#include <iostream>

template <typename KeyType, typename ValueType>
class VectorMap
{
    static_assert(std::is_constructible<ValueType>::value, "ValueType have to have default constructor");
    std::vector<KeyType> keys;
    std::vector<ValueType> values;

public:
    static constexpr bool is_int_key = std::is_same<KeyType, int>::value;

    void insert(KeyType key, ValueType value);
    ValueType &operator[](KeyType key);
    ValueType &at(KeyType key);
    bool isIntKey();
};

template <typename ValueType>
class VectorMap<bool, ValueType>
{
    static_assert(std::is_constructible<ValueType>::value, "ValueType have to have default constructor");
    ValueType true_value;
    ValueType false_value;
    bool false_value_initialized = false;
    bool true_value_initialized = false;

public:
    static constexpr bool is_int_key = false;

    void insert(bool key, ValueType value);
    ValueType &operator[](bool key);
    ValueType &at(bool key);
    bool isIntKey();
};

template <typename KeyType, typename ValueType>
void VectorMap<KeyType, ValueType>::insert(KeyType key, ValueType value)
{
    keys.emplace_back(key);
    values.emplace_back(value);
}

template <typename KeyType, typename ValueType>
ValueType &VectorMap<KeyType, ValueType>::operator[](KeyType key)
{
    auto it = std::find(std::begin(keys), std::end(keys), key);
    if (it == std::end(keys))
    {
        keys.emplace_back(key);
        values.emplace_back(ValueType{});
        return values.back();
    }
    auto dist = std::distance(std::begin(keys), it);
    return values[dist];
}

template <typename KeyType, typename ValueType>
ValueType &VectorMap<KeyType, ValueType>::at(KeyType key)
{
    for (size_t i = 0; i < keys.size(); i++)
        if (keys[i] == key)
        {
            return values[i];
        }
    throw std::out_of_range("key is out of range");
}

template <typename KeyType, typename ValueType>
bool VectorMap<KeyType, ValueType>::isIntKey()
{
    return std::is_integral<KeyType>::value;
}

/////////////////////////////////////////

template <typename ValueType>
void VectorMap<bool, ValueType>::insert(bool key, ValueType value)
{
    if(key)
    {
        true_value = value;
        true_value_initialized = true;
    }
    else
    {
        false_value = value;
        false_value_initialized = true;
    }
}

template <typename ValueType>
ValueType &VectorMap<bool, ValueType>::operator[](bool key)
{
    if(key)
    {
        if(true_value_initialized) { return true_value; }
        true_value = ValueType{};
        return true_value;
    }
    else
    {
        if(false_value_initialized) { return false_value; }
        false_value = ValueType{};
        return false_value;
    }
}

template <typename ValueType>
ValueType &VectorMap<bool, ValueType>::at(bool key)
{
    if(key)
    {
        if(true_value_initialized) return true_value;
        throw std::out_of_range("Key has not been initializated");
    }
    else
    {
        if(false_value_initialized) return false_value;
        throw std::out_of_range("Key has not been initializated");
    }
}

template<typename ValueType>
bool VectorMap<bool, ValueType>::isIntKey()
{
    return false;
}