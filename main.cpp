#include "ulti_sqrt.h"


int main() {
    int i_value = 4;
    double d_value = 9;
    std::vector<double> vector_values= {16, 25};
    std::set<int> set_values = {1, 9};
    i_value = ulti_sqrt(i_value);
    d_value = ulti_sqrt(d_value);
    vector_values = ulti_sqrt(vector_values);
    set_values = ulti_sqrt(set_values);
    std::forward_list<int> fl = {1, 4};
    fl = ulti_sqrt(fl);
    std::cout << "Square root of int: " << i_value << std::endl;
    std::cout << "Square root of double: " << d_value << std::endl;
    for(auto &i : vector_values){
        std::cout << "Square root of vector: " << i << std::endl;
    }
    for(auto &i : fl){
        std::cout << "Square root of forward list: " << i << std::endl;
    }
    for(auto &i : set_values){
        std::cout << "Square root of set: " << i << std::endl;
    }
    return 0;
}