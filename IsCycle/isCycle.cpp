//检测环
//
#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) : data(0), next(NULL) {}

};
//检测环的方法1：快慢指针
//快指针每次移动两步，慢指针每次移动一步，如果有环，则快指针会追上慢指针，否则不会。
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

//检测环的方法2：哈希表
//用哈希表来存储已经遍历过的节点，如果遍历到某个节点时，该节点已经在哈希表中，说明有环。
bool isCycle(Node* head) {
    //定义一个哈希表
    unordered_set<Node*> seen;
    //定义头指针
    Node* curr = head;
    //遍历链表
    while (curr != NULL) {
        //如果当前节点已经在哈希表中，说明有环
        if (seen.find(curr) != seen.end()) {
            return true;
        }
        //否则，将当前节点加入哈希表
        seen.insert(curr);
        //移动到下一个节点
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
    head->next = head->next; //形成环
    cout << isCycle(head) << endl; //输出true
    return 0;
}