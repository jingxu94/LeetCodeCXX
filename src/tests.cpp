#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"
#include "solutions.h"

TEST_CASE("1.Two Sum") {
    SUBCASE("Case 1") {
        std::vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        std::vector<int> expected = {0, 1};
        CHECK(expected == Solution().twoSum(nums, target));
    }
    SUBCASE("Case 2") {
        std::vector<int> nums = {3, 2, 4};
        int target = 6;
        std::vector<int> expected = {1, 2};
        CHECK(expected == Solution().twoSum(nums, target));
    }
    SUBCASE("Case 3") {
        std::vector<int> nums = {3, 3};
        int target = 6;
        std::vector<int> expected = {0, 1};
        CHECK(expected == Solution().twoSum(nums, target));
    }
}

TEST_CASE("2.Add Two Numbers") {
    SUBCASE("Case 1") {
        std::vector<int> l1Array = {2, 4, 3};
        std::vector<int> l2Array = {5, 6, 4};
        std::vector<int> expectedArray = {7, 0, 8};
        ListNode *l1 = VectorToListNode(l1Array);
        ListNode *l2 = VectorToListNode(l2Array);
        ListNode *expected = VectorToListNode(expectedArray);
        CHECK(EqualListNode(Solution().addTwoNumbers(l1, l2), expected));
    }
    SUBCASE("Case 2") {
        std::vector<int> l1Array = {0};
        std::vector<int> l2Array = {0};
        std::vector<int> expectedArray = {0};
        ListNode *l1 = VectorToListNode(l1Array);
        ListNode *l2 = VectorToListNode(l2Array);
        ListNode *expected = VectorToListNode(expectedArray);
        CHECK(EqualListNode(Solution().addTwoNumbers(l1, l2), expected));
    }
    SUBCASE("Case 3") {
        std::vector<int> l1Array = {9, 9, 9, 9, 9, 9, 9};
        std::vector<int> l2Array = {9, 9, 9, 9};
        std::vector<int> expectedArray = {8, 9, 9, 9, 0, 0, 0, 1};
        ListNode *l1 = VectorToListNode(l1Array);
        ListNode *l2 = VectorToListNode(l2Array);
        ListNode *expected = VectorToListNode(expectedArray);
        CHECK(EqualListNode(Solution().addTwoNumbers(l1, l2), expected));
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
