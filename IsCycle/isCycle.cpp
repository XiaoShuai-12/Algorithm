//��⻷
//
#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) : data(0), next(NULL) {}

};
//��⻷�ķ���1������ָ��
//��ָ��ÿ���ƶ���������ָ��ÿ���ƶ�һ��������л������ָ���׷����ָ�룬���򲻻ᡣ
//bool isCycle(Node* head) {
//    if (head == NULL) {
//        return false;
//    }
//    Node* slow = head;
//    Node* fast = head->next;
//    while (slow!= fast) {
//        if (fast == NULL || fast->next == NULL) {
//            return false;
//        }
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return true;
//}

//��⻷�ķ���2����ϣ��
//�ù�ϣ�����洢�Ѿ��������Ľڵ㣬���������ĳ���ڵ�ʱ���ýڵ��Ѿ��ڹ�ϣ���У�˵���л���
bool isCycle(Node* head) {
    //����һ����ϣ��
    unordered_set<Node*> seen;
    //����ͷָ��
    Node* curr = head;
    //��������
    while (curr != NULL) {
        //�����ǰ�ڵ��Ѿ��ڹ�ϣ���У�˵���л�
        if (seen.find(curr) != seen.end()) {
            return true;
        }
        //���򣬽���ǰ�ڵ�����ϣ��
        seen.insert(curr);
        //�ƶ�����һ���ڵ�
        curr = curr->next;
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next = new Node(4);
    head->next = new Node(5);   
    head->next = head->next; //�γɻ�
    cout << isCycle(head) << endl; //���true
    return 0;
}