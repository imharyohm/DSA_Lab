#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *next;
};
typedef struct{
    struct node *top;
}stack;
int push(stack *s,int v){
    struct node *cur;
    cur=malloc(sizeof(struct node));
    if(cur==NULL){
        printf("overflow");
        return 0;
    }
    cur->value=v;
    cur->next=s->top;
    s->top=cur;
    return 0;
}
int pop(stack *s,int *data){
    if(s->top==NULL){
        printf("underflow");
        return 1; 
    }
    struct node *ptr;
    ptr=s->top;
    s->top=s->top->next;
    *data=ptr->value;
    free(ptr);
    return 0;
}
void inti(stack *s){
    s->top=NULL;
}
// void display(stack *s){
//     struct node ptr;
//     for(ptr=s->top;ptr!=NULL;ptr=ptr)
// }
int main(){
    stack s1;
    int value =10;
    inti(&s1);
    int k=push(&s1,value);
    value=15;
    int j=push(&s1,value);
    printf("%d%d",k,j);
    pop(&s1,&value);
    printf("%d",value);

}