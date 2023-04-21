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

public:
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

public:
    // 5.Longest Palindromic Substring
    std::string longestPalindrome(std::string s) {
        if (s.length() < 1) return "";
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = std::max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

private:
    int expandAroundCenter(std::string s, int left, int right) {
        int l = left, r = right;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }

public:
    // 6.Zigzag Conversion
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) return s;
        std::string answer;
        int n = s.size();
        int charsInSection = 2 * (numRows - 1);
        for (int currRow = 0; currRow < numRows; ++currRow) {
            int index = currRow;
            while (index < n) {
                answer += s[index];
                if (currRow != 0 && currRow != numRows - 1) {
                    int charsInBetween = charsInSection - 2 * currRow;
                    int secondIndex = index + charsInBetween;
                    if (secondIndex < n) {
                        answer += s[secondIndex];
                    }
                }
                index += charsInSection;
            }
        }
        return answer;
    }

public:
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

public:
    // 11.Container With Most Water
    int maxArea(std::vector<int> &height) {
        int left = 0, right = height.size() - 1, answer = 0, area;
        while (left < right) {
            area = std::min(height[left], height[right]) * (right - left);
            answer = std::max(answer, area);
            if (height[left] < height[right]) {
                left += 1;
            } else right -= 1;
        }
        return answer;
    }

public:
    // 15.3Sum
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> answer;
        for (int i = 0; i < nums.size(); i++) {
            int sum = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == sum) {
                    answer.emplace_back(std::vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (nums[left] + nums[right] < sum) left++;
                else right--;
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return answer;
    }

};


#endif //TESTLEETCODECXX_SOLUTIONS_H
