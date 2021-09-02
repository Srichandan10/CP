//Author- CHANDAN SRIVASTAVA
//Problem link- 
#include<bits/stdc++.h>
using namespace std;
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

class node{
public:
	int val;
	node *next;
	node():val(0),next(NULL){}
	node(int val):val(val),next(NULL){}
};

void printlist(node *head){
	node *temp=head;
	while(temp){
		cout<<temp->val<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
node* insert_beg(node* head,int x){
	node *temp=new node(x);
	
	temp->next=head;
	return head;
}
node* insert_end(node *head,int x){
	node* temp=new node(x);
	if(head==NULL){
		return temp;
	}
	node *curr=head;
	while(curr->next){
		curr=curr->next;
	}
	curr->next=temp;
	return head;

}

node* del_beg(node* head){
	node* temp=head->next;
	delete head;
	return temp;
}
// detect a loop in linked list and return the node where the cycle begins
node* detectLoop(node* head){
        node* slow=head;
        node* fast=head;
        while(fast!=NULL && slow!=NULL && fast->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                    
                }
                return slow;
                // to remove loop from the linked list
                /*slow=head
                if(slow == fast) {
	               while(fast->next != slow) fast = fast->next;}
	            else {
		           while (slow->next != fast->next) {
		                slow = slow->next;
		                fast = fast->next;
	                }
	                fast->next=NULL;
            	}*/
        	}
            
        }
        return NULL;
}
// reverse a linked list
node* reverse(node* head){
	node* curr=head;
	node* prev=NULL;
	node* next=NULL;
	while(curr){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;

}
//Given a linked list of size N. The task is to reverse every k nodes in the linked list.
node *reverse_k(node *head, int k)
{ 
        if(head==NULL){
            return NULL;
        }
        node* curr=head;
        node* prev=NULL;
        node* next=NULL;
        int count=0;
        
        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
            
        }
        if(head){
            head->next=reverse_k(next,k);
        }
        return prev;
}


int main() {
	file_i_o();
	node *head=new node(10);
	head->next=new node(20);
	head->next->next=new node(30);
	head->next->next->next=new node(40);
	head=insert_end(head,50);
	printlist(head);
	/*head=reverse_k(head,2);
	printlist(head);*/
	//head->next->next->next->next->next = head->next;
	//printlist(head);
	/*node *temp=detectLoop(head);
	cout<<temp->val<<endl;*/
	return 0;
}