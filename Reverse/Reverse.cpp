//反转链表
#include <iostream>
using namespace std;
//定义链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
//反转链表
ListNode* reverseList(ListNode* head) {
    //定义prev，curr，next指针
    ListNode* prev = NULL;
    ListNode* curr = head;
    //反转链表

    while (curr!= NULL) {
        //保存curr的下一个节点
        ListNode* next = curr->next;
        //将curr的next指针指向prev
        curr->next = prev;
        //将prev和curr指针向后移动
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(ListNode* head) {
    while (head!= NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    printList(head);
    ListNode* newHead = reverseList(head);
    printList(newHead);
    return 0;
}