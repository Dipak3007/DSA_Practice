#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* merge(ListNode *list1,ListNode *list2){
    if(!list1)  return list2;
    if(!list2)  return list1;
    ListNode *dummy=new ListNode(0),*p=dummy;
    while(list1 && list2){
        if(list1->val<=list2->val){
            p->next=list1;
            list1=list1->next;
        }
        else{
            p->next=list2;
            list2=list2->next;
        }
        p=p->next;
    }
    if(list1)   p->next=list1;
    if(list2)   p->next=list2;
    p=dummy;
    dummy=dummy->next;
    delete p;
    return dummy;
}

ListNode* mergeSort(ListNode *head){
    if(!head || !head->next)   return head;
    ListNode *fast=head->next,*slow=head,*mid;
    while(fast){
        fast=fast->next;
        if(fast){
            fast=fast->next;
            slow=slow->next;
        }
    }
    mid=slow->next;
    slow->next=nullptr;

    head=mergeSort(head);
    mid=mergeSort(mid);
    return merge(head,mid);
}

int main(){
    int n,i;
    ListNode *head=nullptr,*temp;
    cout<<" Enter no. of nodes : ";
    cin>>n;
    for(i=0;i<n;i++){
        temp=new ListNode(rand()%100,head);
        head=temp;
    }
    cout<<"\nNormal List :\n";
    temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<"\nSorted List :\n";
    head=mergeSort(head);
    temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    return 0;
}