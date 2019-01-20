#include <iostream>
#include <vector>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        ListNode * resultHeader = new ListNode(0);
        ListNode * l1t = l1,
                 * l2t = l2,
                 * rt = resultHeader;

        int add = 0;
        while(true) {
           int v = add;
           if (l1t!=nullptr) {
               v += l1t->val;
               l1t = l1t->next;
           }
           if (l2t!=nullptr) {
               v += l2t->val;
               l2t = l2t->next;
           }
           rt->val = v%10;
           add = v/10;
           if (l1t == nullptr && l2t == nullptr && add == 0) {
               break;
           }
           rt->next = new ListNode(0);
           rt = rt->next;
        }
        return resultHeader;
    }
};

void printNode(ListNode * t) {
    while(t != nullptr) {
       cout << t->val << " ";
       t = t->next;
    }
    cout<<endl;
}

ListNode* initNode(vector<int> arr) {
    ListNode * ret = new ListNode(0);
    ListNode * fret = ret;
    int len = sizeof(arr)/sizeof(int);

    for (int i=0;i< arr.size();++i){
        fret->val = arr[i];
        if (i != arr.size()-1) {
            fret->next = new ListNode(0);
            fret = fret->next;
        }
    }
    return ret;
}

int main() {
    cout << "Hello, World!" << endl;

    auto * s = new Solution();
    vector<int> v1({1,5,9});
    vector<int> v2({9,5});
    auto l1 = initNode(v1);
    auto l2 = initNode(v2);
    auto r = s->addTwoNumbers(l1,l2);
    printNode(r);
    return 0;
}

// 10进制转2进制
