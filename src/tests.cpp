#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"
#include "solutions.h"

TEST_CASE("1.Two Sum") {
    SUBCASE("Case 1") {
        std::vector<int> nums{2, 7, 11, 15};
        int target = 9;
        std::vector<int> expected{0, 1};
        CHECK(expected == Solution().twoSum(nums, target));
    }
    SUBCASE("Case 2") {
        std::vector<int> nums{3, 2, 4};
        int target = 6;
        std::vector<int> expected{1, 2};
        CHECK(expected == Solution().twoSum(nums, target));
    }
    SUBCASE("Case 3") {
        std::vector<int> nums{3, 3};
        int target = 6;
        std::vector<int> expected{0, 1};
        CHECK(expected == Solution().twoSum(nums, target));
    }
}

TEST_CASE("2.Add Two Numbers") {
    SUBCASE("Case 1") {
        std::vector<int> l1Array{2, 4, 3}, l2Array{5, 6, 4}, expectedArray{7, 0, 8};
        ListNode *l1 = VectorToListNode(l1Array);
        ListNode *l2 = VectorToListNode(l2Array);
        ListNode *expected = VectorToListNode(expectedArray);
        CHECK(EqualListNode(Solution().addTwoNumbers(l1, l2), expected));
    }
    SUBCASE("Case 2") {
        std::vector<int> l1Array{0}, l2Array{0}, expectedArray{0};
        ListNode *l1 = VectorToListNode(l1Array);
        ListNode *l2 = VectorToListNode(l2Array);
        ListNode *expected = VectorToListNode(expectedArray);
        CHECK(EqualListNode(Solution().addTwoNumbers(l1, l2), expected));
    }
    SUBCASE("Case 3") {
        std::vector<int> l1Array{9, 9, 9, 9, 9, 9, 9}, l2Array{9, 9, 9, 9}, expectedArray{8, 9, 9, 9, 0, 0, 0, 1};
        ListNode *l1 = VectorToListNode(l1Array);
        ListNode *l2 = VectorToListNode(l2Array);
        ListNode *expected = VectorToListNode(expectedArray);
        CHECK(EqualListNode(Solution().addTwoNumbers(l1, l2), expected));
    }
}

TEST_CASE("5.Longest Palindromic Substring") {
    SUBCASE("Case 1") {
        std::string s{"babad"}, expected{"aba"};
        CHECK(Solution().longestPalindrome(s) == expected);
    }
    SUBCASE("Case 2") {
        std::string s{"cbbd"}, expected{"bb"};
        CHECK(Solution().longestPalindrome(s) == expected);
    }
}

TEST_CASE("6.Zigzag Conversion") {
    SUBCASE("Case 1") {
        std::string s{"PAYPALISHIRING"}, expected{"PAHNAPLSIIGYIR"};
        int numRows = 3;
        CHECK(Solution().convert(s, numRows) == expected);
    }
    SUBCASE("Case 2") {
        std::string s{"PAYPALISHIRING"}, expected{"PINALSIGYAHRPI"};
        int numRows = 4;
        CHECK(Solution().convert(s, numRows) == expected);
    }
    SUBCASE("Case 3") {
        std::string s{"A"}, expected{"A"};
        int numRows = 1;
        CHECK(Solution().convert(s, numRows) == expected);
    }
}

TEST_CASE("9.Palindrome Number") {
    SUBCASE("Case 1") {
        int x = 121;
        CHECK(Solution().isPalindrome(x));
    }
    SUBCASE("Case 2") {
        int x = -121;
        CHECK(!(Solution().isPalindrome(x)));
    }
    SUBCASE("Case 3") {
        int x = 10;
        CHECK(!(Solution().isPalindrome(x)));
    }
}

TEST_CASE("11.Container With Most Water") {
    SUBCASE("Case 1") {
        std::vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
        int expected = 49;
        CHECK(Solution().maxArea(height) == expected);
    }
    SUBCASE("Case 2") {
        std::vector<int> height{1, 1};
        int expected = 1;
        CHECK(Solution().maxArea(height) == expected);
    }
}

TEST_CASE("15.3Sum") {
    SUBCASE("Case 1") {
        std::vector<int> nums{-1, 0, 1, 2, -1, -4};
        std::vector<std::vector<int>> expected{{-1, -1, 2},
                                               {-1, 0,  1}};
        CHECK(Solution().threeSum(nums) == expected);
    }
    SUBCASE("Case 2") {
        std::vector<int> nums{0, 1, 1};
        std::vector<std::vector<int>> expected{};
        CHECK(Solution().threeSum(nums) == expected);
    }
    SUBCASE("Case 3") {
        std::vector<int> nums{0, 0, 0};
        std::vector<std::vector<int>> expected{{0, 0, 0}};
        CHECK(Solution().threeSum(nums) == expected);
    }
}