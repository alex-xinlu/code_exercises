#include <utility>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // 翻转一个子链表，并且返回新的头与尾
    void myReverse(ListNode* head, ListNode* tail, ListNode*& newHead, ListNode*& newTail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        newHead = tail;
        newTail = head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            ListNode* newHead, * newTail;
            myReverse(head, tail, newHead, newTail);
            // 把子链表重新接回原链表
            pre->next = newHead;
            newTail->next = nex;
            pre = newTail;
            head = nex;
        }

        return hair->next;
    }
};
