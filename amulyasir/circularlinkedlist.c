#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void create(struct node **h,int value){
    struct node*cur,*ptr;
    cur=(struct node*)malloc(sizeof(struct node));
    cur->next=NULL;
    cur->data=value;
    if(*h==NULL){
        *h=cur;
        cur->next=*h;
    }
    else{
        cur->next=*h;
        ptr->next=cur;
        ptr=cur;
    }
}
void insert(struct node **h,int value,int pos){
    struct node *cur,*temp;
    cur=malloc(sizeof(struct node));
    cur->next=NULL;
    cur->data=value;
    if(*h==NULL){
        *h=cur;
        cur->next=*h;
    }
    else if(pos==0){
        temp=*h;
        while(temp->next!=*h){
            temp=temp->next;
        }
        cur->next=*h;
        *h=cur;
        temp->next=cur;
    }
    else{
        temp=*h;
        int i=0;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
            cur->next=temp->next;
            temp->next=cur;


    }
}
void display(struct node *h){
    struct node *ptr;
    if(h!=NULL){
        ptr=h;
        while(ptr->next!=h){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("%d ",ptr->data);
    }
}
int main(){
    struct node *head=NULL;
    create(&head,34);
    insert(&head,43,0);
    insert(&head,55,1);
     insert(&head,53,2);
      insert(&head,54,3);
       insert(&head,33,4);
        insert(&head,15,5);
         insert(&head,5,6);
    display(head);
}