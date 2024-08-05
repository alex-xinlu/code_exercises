#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int x) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (node) {
        node->val = x;
        node->next = NULL;
    }
    return node;
}

void myReverse(struct ListNode* head, struct ListNode* tail, struct ListNode** newHead, struct ListNode** newTail) {
    struct ListNode* prev = tail->next;
    struct ListNode* p = head;
    while (prev != tail) {
        struct ListNode* nex = p->next;
        p->next = prev;
        prev = p;
        p = nex;
    }
    *newHead = tail;
    *newTail = head;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* hair = createNode(0);
    hair->next = head;
    struct ListNode* pre = hair;

    while (head) {
        struct ListNode* tail = pre;
        // 查看剩余部分长度是否大于等于 k
        for (int i = 0; i < k; ++i) {
            tail = tail->next;
            if (!tail) {
                return hair->next;
            }
        }
        struct ListNode* nex = tail->next;
        struct ListNode* newHead, * newTail;
        myReverse(head, tail, &newHead, &newTail);
        // 把子链表重新接回原链表
        pre->next = newHead;
        newTail->next = nex;
        pre = newTail;
        head = nex;
    }

    return hair->next;
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void freeList(struct ListNode* head) {
    struct ListNode* tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original list: ");
    printList(head);

    int k = 2;
    head = reverseKGroup(head, k);

    printf("Reversed list in groups of %d: ", k);
    printList(head);

    freeList(head);

    return 0;
}
