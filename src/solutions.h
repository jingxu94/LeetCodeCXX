//
// Created by Xu Jing on 2023/4/20.
//

#ifndef TESTLEETCODECXX_SOLUTIONS_H
#define TESTLEETCODECXX_SOLUTIONS_H

#include <unordered_map>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool EqualListNode(ListNode *l1, ListNode *l2) {
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val != l2->val) { return false; }
        l1 = l1->next;
        l2 = l2->next;
    }
    return (l1 == nullptr && l2 == nullptr);
}

ListNode *VectorToListNode(std::vector<int> numbers) {
    ListNode *dummyHead = new ListNode(0);
    ListNode *curr = dummyHead;
    for (int i = 0; i < numbers.size(); i++) {
        curr->next = new ListNode(numbers[i]);
        curr = curr->next;
    }
    return dummyHead->next;
}

class Solution {
public:
    // 1.Two Sum
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {-1, -1};
    }

    // 2.Add Two Numberes
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *curr = dummyHead;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummyHead->next;
    }

    // 9.Palindrome Number
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int div = 1;
        while (x / div >= 10) {
            div *= 10;
        }
        while (x > 0) {
            int left = x / div;
            int right = x % 10;
            if (left != right) return false;
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
};

#endif //TESTLEETCODECXX_SOLUTIONS_H
