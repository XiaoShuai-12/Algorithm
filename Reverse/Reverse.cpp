//��ת����
#include <iostream>
using namespace std;
//��������ڵ�
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
//��ת����
ListNode* reverseList(ListNode* head) {
    //����prev��curr��nextָ��
    ListNode* prev = NULL;
    ListNode* curr = head;
    //��ת����

    while (curr!= NULL) {
        //����curr����һ���ڵ�
        ListNode* next = curr->next;
        //��curr��nextָ��ָ��prev
        curr->next = prev;
        //��prev��currָ������ƶ�
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