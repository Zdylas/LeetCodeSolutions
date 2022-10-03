/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iterator>
#include <iomanip>
#include <string>
#include <list>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /*
     * Completed Using Iteration
     *
     * IMPORANT: Recursion in theory takes longer because of having to store all the function calls in the stack
     * to allow the return back to the the caller functions.
     * 
     * IMPORTANT: Anything done recursively can be done iteratively, recursion is used as a means to create an easier problem
     * along with being easily readable by others. 
     */ 
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2; 
        if (!list2) return list1;

        bool list1_less = (list1->val < list2->val);
        ListNode* head = list1_less ? list1 : list2;
        
        if (list1_less) {
            list1 = list1->next;
        } else {
            list2 = list2->next;
        }

        ListNode* tail = head;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
                tail = tail->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
                tail = tail->next;
                
            }
        }
        if (list1) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        return head;
    }


    /*
     * Once again using recursion this time instead of creating new nodes in the heap use
     * pre-existing nodes to set the next values.
     */ 
    ListNode* mergeTwoListsRecursive(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        } else if (!list2) {
            return list1;
        }
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
    /*
     * First attempt using malloc, this means im creating an entirely new list of pointers and values
     * which means lots of memory is wasted, as I already have all the Nodes I should need.
     */
    ListNode* mergeTwoListsMalloc(ListNode* list1, ListNode* list2) {
        if (!(list1 && list2)) {
            if (list1) {
                return list1;
            } else if (list2) {
                return list2;
            }
            return nullptr;
        }

        if (list1->val <= list2->val) {
            ListNode* ptr = (ListNode*) malloc(sizeof(ListNode));
            *ptr = {list1->val, mergeTwoLists(list1->next, list2)};
            return ptr;
        } else {
            ListNode* ptr = (ListNode*) malloc(sizeof(ListNode));
            *ptr = {list2->val, mergeTwoLists(list1, list2->next)};
            return ptr;
        }
    }
};

int main()
{
    Solution TestSolution;
    
    ListNode list1_3 = {6};
    ListNode list1_2 = {5, &list1_3};
    ListNode list1_1 = {4, &list1_2};

    ListNode list2_3 = {3};
    ListNode list2_2 = {2, &list2_3};
    ListNode list2_1 = {1, &list2_2};
    
    ListNode* start = TestSolution.mergeTwoLists(&list1_1, &list2_1);
    
    while (start) {
        cout << start->val << endl;
        start = start->next;
    }
}
