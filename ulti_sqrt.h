#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <type_traits>

// main traits template
template <typename T, typename = void>
struct traits{
    static constexpr bool value = false;
};

// specialization for std::vector
template <typename T>
struct traits<std::vector<T>> {
    using type = std::vector<T>;
    static constexpr bool value = true;
};

// specialization for std::list
template <typename T>
struct traits<std::list<T>> {
    using type = std::list<T>;
    static constexpr bool value = true;
};

// specialization for std::forward_list
template <typename T>
struct traits<std::forward_list<T>> {
    using type = std::forward_list<T>;
    static constexpr bool value = true;
};

// specialization for std::set
template <typename T>
struct traits<std::set<T>> {
    using type = std::set<T>;
    static constexpr bool value = true;
};

// specialization for std::unordered_set
template <typename T>
struct traits<std::unordered_set<T>> {
    using type = std::unordered_set<T>;
    static constexpr bool value = true;
};

// specialization for std::map
template <typename K, typename V>
struct traits<std::map<K, V>> {
    using type = std::map<T>;
    static constexpr bool value = true;
};

// specialization for std::unordered_map
template <typename K, typename V>
struct traits<std::unordered_map<K, V>> {
    using type = std::unordered_map<T>;
    static constexpr bool value = true;
};



// main template
template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, bool>::type = true>

T ulti_sqrt(const T &value)
{
    if(value < 0){
        throw std::invalid_argument("Cannot calculate square root of a negative number");
    }
    return std::sqrt(value);
}

// partial specialization for container
template <typename Container, typename std::enable_if_t<
    traits<Container>::value, bool> = true>

Container ulti_sqrt(const Container &container)
{

    Container result;

    if constexpr (typename std::is_same_v<traits<Container>::type, std::map> == true || typename std::is_same<traits<Container>::type, std::unordered_map> == true) {
        for (const auto &pair : container) {
            result.emplace(pair.first, ulti_sqrt(pair.second));
        }
    } else if constexpr (typename std::is_same_v<traits<Container>::type, std::set> == true || typename std::is_same_v<traits<Container>::type, std::unordered_set> == true) {
        for (const auto &elem : container) {
            result.insert(ulti_sqrt(elem));
        }
    } else if constexpr (typename std::is_same_v<traits<Container>::type, std::forward_list> == true) {
        for (const auto &elem : container) {
            result.push_front(ulti_sqrt(elem));
        }
    } else {
        for (const auto &elem : container) {
            result.push_back(ulti_sqrt(elem));
        }
    }
    return result;
}

template <typename Container, typename std::enable_if_t<
    traits<Container>::value && std::is_same_v<typename traits<Container>::type, std::set>
    && std::is_same_v<typename traits<Container>::type, std::unordered_map>, bool> = true>

Container ulti_sqrt(const Container &container)
{
    Container result;
    if constexpr (typename std::is_same_v<traits<Container>::type, std::map> == true || typename std::is_same<traits<Container>::type, std::unordered_map> == true) {
        for (const auto &pair : container) {
            result.emplace(pair.first, ulti_sqrt(pair.second));
        }
        }
    return result;
}

template <typename Container, typename std::enable_if_t<
    traits<Container>::value && std::is_same_v<traits<Container>::type, std::map>, bool> = true>

Container ulti_sqrt(const Container &container)
{
    Container result;
    if constexpr (typename std::is_same_v<traits<Container>::type, std::map> == true || typename std::is_same<traits<Container>::type, std::unordered_map> == true) {
        for (const auto &pair : container) {
            result.emplace(pair.first, ulti_sqrt(pair.second));
        }
        }
    return result;
}