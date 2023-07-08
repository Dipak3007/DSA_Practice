#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//using iteration
ListNode* reverse(ListNode *head){
    ListNode *prev=nullptr,*curr=head;         //using three pointers for reversal
    while(curr){
        ListNode *nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}

//using recursion
ListNode* reverseRec(ListNode *head,ListNode *prev){
    if(!head) return prev;
    ListNode *nxt=head->next;
    head->next=prev;
    return reverseRec(nxt,head);
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
    cout<<"\nReversed List :\n";
    head=reverse(head);
    temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    return 0;
}