#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct
{
    char data[MAX];
    int top;
} stack;
stack s1;
void inti(stack *s)
{
    s->top = -1;
}
int isEmpty(stack s)
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}
int push(stack *s,int x){
    if(s->top==MAX-1){
        //printf("Stack is full");
        return 1;
    }
    s->top++;
    s->data[s->top]=x;
    return 0;
}
int pop(stack *s,int *x){
    if(s->top==-1){
        //printf("underflow");
        return 1;
    }
    *x=s->data[s->top];
    s->top--;
    return 0;
}
void copy(stack *s,stack *r){
    int d;
    if(!isEmpty(*s)){
        pop(s,&d);
        copy(s,r);
        push(r,d);
    }
}

int main(){
    int k;
    stack s1,r;
    inti(&s1);
    inti(&r);
    k=push(&s1,10);
    k=push(&s1,20);
    k=push(&s1,30);
    k=push(&s1,40);
    k=push(&s1,50);
    copy(&s1,&r);
        for(int i=0;i<=s1.top;i++){
        printf("%d ",s1.data[i]);
    }
    return 0;
}