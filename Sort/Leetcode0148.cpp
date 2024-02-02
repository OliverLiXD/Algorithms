#include "../DataStructures/DataStructures.h"
#include "iostream"

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
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* p1 = head;
        ListNode* p2 = head;

        while(p2->next != NULL && p2->next->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        ListNode* temp = p1;
        p1 = p1->next;
        temp->next = NULL;

        ListNode* r1 = sortList(head);
        ListNode* r2 = sortList(p1);

        ListNode* res = mergeList(r1, r2);

        return res;

    }

    static ListNode* mergeList(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) {
            return l2;
        }
        if(l2 == NULL) {
            return l1;
        }

        if(l2->val < l1->val) {
            ListNode* temp = l2;
            l2 = l1;
            l1 = temp;
        }
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        while(p1->next != NULL && p2 != NULL) {
            if(p2->val < p1->next->val) {
                ListNode* t1 = p1->next;
                ListNode* t2 = p2->next;

                p1->next = p2;
                p2->next = t1;
                p1 = p1->next;
                p2 = t2;
                continue;
            }
            p1 = p1->next;
        }

        if(p2 != NULL) {
            p1->next = p2;
        }

        return l1;
    }
};
