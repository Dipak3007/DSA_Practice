/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroups(ListNode *head,int k){
    if(!head)   return nullptr;
    ListNode *p=head;
    int n=k;
    while(p && n){
        p=p->next;
        n--;
    }
    if(n)   return head;
    n=k;
    ListNode *prev=nullptr,*curr=head;
    while(curr && n){
        ListNode *nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
        n--;
    }
    head->next=reverseKGroups(curr,k);
    return prev;
}

int main(){
    int n,i,k;
    ListNode *head=nullptr,*temp;
    cout<<" Enter no. of nodes : ";
    cin>>n;
    cout<<" Enter k : ";
    cin>>k;
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
    cout<<"\nReversed List in K-Groups :\n";
    head=reverseKGroups(head,k);
    temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    return 0;
}