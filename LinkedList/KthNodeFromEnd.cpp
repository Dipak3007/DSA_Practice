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

ListNode* kthNode(ListNode *head,int k){
    ListNode *fast=head,*slow=head;
    while(k--)
        fast=fast->next;        //fast is k steps away from slow
    while(fast){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
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
    cout<<"\nKth node from end :";
    temp=kthNode(head,k);
    cout<<temp->val;
    return 0;
}