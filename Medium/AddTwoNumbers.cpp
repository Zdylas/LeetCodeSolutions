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
     * Much cleaner code using the exact same method seen in addTwoNumbers Heap
     *
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int remainder = 0;
        ListNode* start_1 = l1;
        ListNode* start_2 = l2;
        bool start_node = false;
        while (l1 || l2) {
            remainder += (l1? l1->val : 0) + (l2? l2->val : 0);
            // If the node exists set the node to first digit of remainder
            if (l1) l1->val = remainder % 10;
            if (l2) l2->val = remainder % 10;
            remainder /= 10;

            if (!l2) {
                if (!l1->next) {
                    start_node = true;
                    break;
                }
            } else if (!l1) {
                if (!l2->next) {
                    break;
                }
            } else if (!l1->next && !l2->next) {
                break;
            }
            
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            
        }

        if (start_node && remainder > 0) {;
            l1->next = new ListNode(remainder);
            return start_1;
        } else if (!start_node && remainder > 0) {
            l2->next = new ListNode(remainder);
            return start_2;
        }
        return start_node ? start_1 : start_2;
    }
    /*
     * Much cleaner code that creates a new ListNode every iteration of the while loop, this means it 
     * requires extra memory allocated. (Time is also possibly slower because of allocation?)
     */
    ListNode* addTwoNumbersHeap(ListNode* l1, ListNode* l2) {
        ListNode result(0);  
        ListNode* result_ptr = &result;
        
        int carry = 0;
        
        while (l1 or l2 or carry) {
            carry += (l1? l1->val : 0) + (l2? l2->val : 0);
            result_ptr->next = new ListNode(carry % 10);
            carry /= 10;
            result_ptr = result_ptr->next;
            
            // This code can be utilized so that you don't need multiple checks of whether l1 or l2 exits,
            // This means overall cleaner code.
            l1 = l1? l1->next : nullptr;
            l2 = l2? l2->next : nullptr;
        }
        return result.next;
    }


    /*
     * First attempt, feel the code could be written much better, uses one heap creation for for overflo
     * i.e. [5] and [5] would need extra slot for [0,1].
     */
    ListNode* addTwoNumbersFirst(ListNode* l1, ListNode* l2) {
        int carry_over = 0;
        int total = 0;
        ListNode* start_1 = l1;
        ListNode* start_2 = l2;
        bool start_node = false;
        while (l1 || l2) {
            if (!l1) {
                total = l2->val + carry_over;
                carry_over = 0;
                if (total >= 10) {
                    carry_over++;
                    total -= 10;
                }
                l2->val = total;

                if (!l2->next) {
                    break;
                }
                l2 = l2->next;
                
            } else if (!l2) {
                start_node = true;
                total = l1->val + carry_over;
                carry_over = 0;
                if (total >= 10) {
                    carry_over++;
                    total -= 10;
                }
                l1->val = total;

                if (!l1->next) {
                    break;
                }
                l1 = l1->next;
                

            } else {
                total = l1->val + l2->val + carry_over;
                carry_over = 0;
                if (total >= 10) {
                    carry_over++;
                    total -= 10;
                }

                l1->val = total;
                l2->val = total;
                if (!l1->next && !l2->next) {
                    break;
                }
                l1 = l1->next;
                l2 = l2->next;
            }

        }
        if (start_node && carry_over > 0) {;
            l1->next = new ListNode(carry_over);
            return start_1;
        } else if (!start_node && carry_over > 0) {
            l2->next = new ListNode(carry_over);
            return start_2;
        }

        return start_node ? start_1 : start_2;
    }
};

int main(void)
{
    Solution MySol;

    ListNode list1_7 = {5};
    ListNode list1_6 = {0, &list1_7};
    ListNode list1_5 = {9, &list1_6};
    ListNode list1_4 = {9, &list1_5};
    ListNode list1_3 = {3};
    ListNode list1_2 = {4, &list1_3};
    ListNode list1_1 = {2, &list1_2};
    

    ListNode list2_4 = {5};
    ListNode list2_3 = {4};
    ListNode list2_2 = {6, &list2_3};
    ListNode list2_1 = {5, &list2_2};


    ListNode* start_pointer = MySol.addTwoNumbers(&list1_7, &list2_4);
    while (start_pointer) {
        cout << start_pointer->val << endl;
        start_pointer = start_pointer->next;
    }
}