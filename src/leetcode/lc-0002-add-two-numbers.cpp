#include <iostream>
#include <vector>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp1=l1;
        ListNode* tmp2=l2;
        ListNode* s=new ListNode();
        ListNode* f=s;
        int sum=0;
        bool flag=false;
        while(l1!=nullptr||l2!=nullptr){
            if(l1!=nullptr&&l2!=nullptr){
                if(flag){
                    sum=l1->val+l2->val+1;
                    if(sum>=10){
                        s->val=sum%10;
                        flag=true;
                    } else {
                        s->val=sum;
                        flag=false;
                    }
                } else {
                    sum=l1->val+l2->val;
                    if(sum>=10){
                        s->val=sum%10;
                        flag=true;
                    } else {
                        s->val=sum;
                        flag=false;
                    }
                }
            } else if(l1!=nullptr){
                if(flag){
                    sum=1+l1->val;
                    if(sum>=10){
                        s->val=sum%10;
                        flag=true;
                    } else {
                        s->val=sum;
                        flag=false;
                    }
                } else {
                    sum=l1->val;
                    if(sum>=10){
                        s->val=sum%10;
                        flag=true;
                    } else {
                        s->val=sum;
                        flag=false;
                    }
                }
            } else if(l2!=nullptr){
                if(flag){
                    sum=1+l2->val;
                    if(sum>=10){
                        s->val=sum%10;
                        flag=true;
                    } else {
                        s->val=sum;
                        flag=false;
                    }
                } else {
                    sum=l2->val;
                    if(sum>=10){
                        s->val=sum%10;
                        flag=true;
                    } else {
                        s->val=sum;
                        flag=false;
                    }
                }
            }
            if(l1!=nullptr) l1=l1->next;
            if(l2!=nullptr) l2=l2->next;
            if(l1!=nullptr||l2!=nullptr) {
                s->next=new ListNode();
                s=s->next;
            }
        }
        if(flag) s->next=new ListNode(1);
        return f;
    }
};

int main() {
    ListNode* l1=new ListNode();
    ListNode* l2=new ListNode();
    ListNode* tmp=new ListNode();
    int n1,n2,a,b;
    cin>>n1>>n2;
    l1=tmp;
    while (n1-->0) {
        cin>>a;
        tmp->val=a;
        if (n1>0) {
            ListNode* t=new ListNode();
            tmp->next=t;
            if (tmp!=nullptr) tmp=tmp->next;
        }
    }

    tmp=new ListNode();
    l2=tmp;
    while (n2-->0) {
        cin>>b;
        tmp->val=b;
        if (n2>0) {
            ListNode* t=new ListNode();
            tmp->next=t;
            if (tmp!=nullptr) tmp=tmp->next;
        }
    }

    Solution s;
    ListNode* sol=s.addTwoNumbers(l1,l2);
    while (sol!=nullptr) {
        cout<<sol->val;
        sol=sol->next;
        if (sol!=nullptr) cout<<"->";
    }
    cout<<"\n";
    return 0;
}