//
//  21.cpp
//  LeetCode
//
//  Created by 윤하연 on 2021/04/12.
//
//  21. Merge Two Sorted Lists
//
//  Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.


#include <algorithm>
#include <iostream>
#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
public:
    std::string ToString() {
        std::string str = std::to_string(val);
        while (next!=nullptr) {
            str += ", " + std::to_string(next -> val);
            next = next->next;
        }
        return str;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* resultList = new ListNode();
        ListNode* nextNode = new ListNode();
        resultList = nextNode;
        
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        
        bool isLeftSmall = false;
        
        while (true) {
            if (l1 == nullptr) isLeftSmall = false;
            else if (l2 == nullptr) isLeftSmall = true;
            else isLeftSmall = l1->val < l2->val;
            
            if (isLeftSmall) {
                nextNode->val = l1->val;
                l1 = l1->next;
            }
            else {
                nextNode->val = l2->val;
                l2 = l2->next;
            }
            
            if (l1 == nullptr && l2 == nullptr) break;
            
            nextNode->next = new ListNode();
            nextNode = nextNode->next;
        }
        return resultList;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    std::vector<ListNode*> input[] = {{new ListNode(1,new ListNode(2,new ListNode(4))),new ListNode(1,new ListNode(3,new ListNode(4)))}};
    ListNode* answer[] = {new ListNode(1,new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(4))))))};
    for (int i = 0 ; i < sizeof(input) / sizeof(input[0]); i++) {
        ListNode* result = solution.mergeTwoLists(input[i][0],input[i][1]);
        if (result != answer[i]) {
            std::cout << std::to_string(i) << " Answer: " << answer[i]->ToString() << "  My Answer: " << result->ToString() << std::endl;
        }
    }
    return 0;
}
