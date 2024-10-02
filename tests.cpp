#include "ulti_sqrt.h"
#include <gtest/gtest.h>

TEST(sqrt_test, Int_test1) {
    int a = 0;
    a = ulti_sqrt(a);
    EXPECT_EQ(a, 0);
}

TEST(sqrt_test, Int_test2) {
    int a = 9;
    a = ulti_sqrt(a);
    EXPECT_EQ(a, 3);
}

TEST(sqrt_test, floattest1) {
    float a = 9;
    a = ulti_sqrt(a);
    EXPECT_NEAR(a, 3, 0.0001);
}

TEST(sqrt_test, vector_test1) {
    std::vector<int> a = {16, 25};
    a = ulti_sqrt(a);
    EXPECT_EQ(a[0], 4);
    EXPECT_EQ(a[1], 5);
}

TEST(sqrt_test, vector_test2) {
    std::vector<int> a = {0, 9};
    a = ulti_sqrt(a);
    EXPECT_EQ(a[0], 0);
    EXPECT_EQ(a[1], 3);
}

TEST(sqrt_test, list_test) {
    std::list<int> a = {0, 9};
    a = ulti_sqrt(a);
    EXPECT_EQ(a.front(), 0);
    EXPECT_EQ(a.back(), 3);
}

TEST(sqrt_test, forward_list_test) {
    std::forward_list<int> a = {0, 9};
    a = ulti_sqrt(a);
    EXPECT_EQ(a.front(), 3);
    a.pop_front();
    EXPECT_EQ(a.front(), 0);
}

TEST(sqrt_test, set_test) {
    std::set<int> a = {0, 9};
    a = ulti_sqrt(a);
    EXPECT_EQ(*a.find(0), 0);
    EXPECT_EQ(*a.find(3), 3);
}

TEST(sqrt_test, unorderedset_test) {
    std::unordered_set<int> a = {0, 9};
    a = ulti_sqrt(a);
    EXPECT_EQ(*a.find(0), 0);
    EXPECT_EQ(*a.find(3), 3);
}

TEST(sqrt_test, map_test) {
    std::map<std::string, int> a;
    a["first number"] = 1;
    a["second number"] = 9;
    a = ulti_sqrt(a);
    EXPECT_EQ(a["first number"], 1);
    EXPECT_EQ(a["second number"], 3);
}

TEST(sqrt_test, unorderedmap_test) {
    std::unordered_map<std::string, int> a;
    a["first number"] = 1;
    a["second number"] = 9;
    a = ulti_sqrt(a);
    EXPECT_EQ(a["first number"], 1);
    EXPECT_EQ(a["second number"], 3);
}