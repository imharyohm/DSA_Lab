//Implementation of stack using array
#include<stdio.h>
#define MAX 6
typedef struct{
    int data[MAX];
    int top;
}STACK;
int push(STACK *s,int x){
    if(s->top==MAX-1){
        printf("Stack is full");
        return 1;
    }
    s->top++;
    s->data[s->top]=x;
    return 0;
}
int pop(STACK *s,int *x){
    if(s->top==-1){
        printf("underflow");
        return 1;
    }
    *x=s->data[s->top];
    s->top--;
    return 0;
}
int main(){
    int k;
    STACK s1;
    s1.top=-1;
    k=push(&s1,10);
    k=push(&s1,20);
    k=push(&s1,30);
    k=push(&s1,40);
    k=push(&s1,50);
    printf("-----Array before pop------\n");
    for(int i=0;i<=s1.top;i++){
        printf("%d ",s1.data[i]);
    }
    int value;
    int a=pop(&s1,&value);
    if(a==0){
        printf("\nThe poped value:%d\n",value);
    }
    printf("-----Array after pop------\n");
    for(int i=0;i<=s1.top;i++){
        printf("%d ",s1.data[i]);
    }
    return 0;
}