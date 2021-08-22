#include <bits/stdc++.h>
using namespace std;
 
struct Node{
	int data;
	struct Node*npx;
};
struct Node *head=NULL,*tail=NULL;
int size=0;
 
 
struct Node* Xor(struct Node *prev,  struct Node *next)
{
   return ( struct Node*)((uintptr_t)(prev) ^ (uintptr_t)(next));
}
void push_back(int x){
	struct Node *nn=(struct Node*)malloc(sizeof (struct Node*));
	nn->data=x;
    if(head==NULL)
    head=tail=nn;
    else{
    	tail->npx=Xor(tail->npx,nn);
    	nn->npx=tail;
    	tail=nn;
    }
    size++;
}
 
void push_front(int x){
	struct Node *nn=(struct Node*)malloc(sizeof (struct Node*));
	nn->data=x;
	if(head==NULL)
	head=tail=nn;
	else{
		head->npx=Xor(head->npx,nn);
		nn->npx=head;
		head=nn;
	}
	size++;
}
 
void pop_back(){
	struct Node*ptr;
	if(head==NULL|| tail==NULL){
		printf("list is empty");
	    return;
	}
	else{
		ptr=tail;
		struct Node *prev=Xor(ptr->npx,NULL);
		if(prev==NULL){
		    head=NULL;
		}
		else{
			prev->npx=Xor(ptr,Xor(prev->npx,NULL));
		}
		tail=prev;
		if(tail==NULL)head=NULL;
		free(ptr);
	}
	size--;
}
 
void pop_front(){
	struct Node *ptr=head;
	if(head==NULL || tail==NULL){
		printf("list is empty");
	    return;
	}
	else{
		struct Node *next=Xor(NULL,ptr->npx);
		if(next==NULL)
		tail=NULL;
		else{
			ptr=head;
			next->npx=Xor(ptr,Xor(NULL,next->npx));
		}
		head=next;
		if(tail==NULL)head=NULL;
		free(ptr);
	}
	size--;
}
 
int get_front(){
	if(head==NULL)
	return -1;
	int p=head->data;
	return p;
}
 
int get_back(){
	if(tail==NULL)
	return -1;
	else{
		int q=tail->data;
		return q;
	}
 
}
 
int get_secondback(){
	if(tail==NULL)
	return -1;
	struct Node *prev=Xor(tail->npx,NULL);
	if(prev==NULL)
	return -1;
	else{
		int p=prev->data;
		return p;
	}
}
 
int get_secondfront(){
	if(head==NULL)
	return -1;
	struct Node *next=Xor(next->npx,NULL);
	if(next==NULL)
	return -1;
	else{
		int q=next->data;
		return q;
	}
}
 
long long int deque_Size(){
	return size;
}
 
bool empty(){
	if(head==NULL)
	return true;
	return false;
}
int main() {
	while(1){
		int x;cin>>x;
		if(x==0)break;
		int ch;cin>>ch;
        switch(ch){
     	case 1:cout<<empty()<<"\n";break;
     	case 2:int a;cin>>a;push_back(a);cout<<deque_Size()<<"\n";break;
     	case 3:int b;cin>>b;push_front(b);cout<<deque_Size()<<"\n";break;
     	case 4:pop_back();break;
     	case 5:pop_front();break;
     	case 6:cout<<get_front()<<" ";break;
     	case 7:cout<<get_back()<<" ";break;
     	case 8:cout<<get_secondback()<<" ";break;
     	case 9:cout<<get_secondfront()<<" ";break;
     	case 10:cout<<deque_Size()<<" ";break;
     	default:break;
        }
	}
 
	return 0;
}