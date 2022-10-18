#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct
{
    char data[MAX];
    int top;
} Stack;
Stack s1;
void init(Stack *s)
{
    s->top = -1;
}
int isEmpty(Stack s)
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}
int push(Stack *s, char c)
{
    if (s->top == MAX - 1)
    {
        return 1;
    }
    else
    {
        s->data[++s->top] = c;
        return 0;
    }
}
int pop(Stack *s, char *v)
{
    if (s->top == -1)
    {
        // printf("Stack Underflow\n");
        return 1;
    }
    else
    {
        *v = s->data[s->top];
        s->top--;
        return 0;
    }
}
int isoperand(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    else
        return 0;
}
int getv(char d)
{
    int k = 0;
    switch (d)
    {
    case '+':
    case '-':
        k = 1;
        break;
    case '*':
    case '/':
        k = 2;
        break;
    }
    return k;
}
int isLH(char a, char b)
{
    if (getv(a) < getv(b))
        return 1;
    else
        return 0;
}
void inf_to_pos(char *inf, char *out)
{
    int i = 0, j = 0, k;
    char t;
    while (inf[i] != '\0')
    {
        if (isoperand(inf[i]))
            out[j++] = inf[i];
        else if (inf[i] == '(')
            push(&s1, inf[i]);
        else if (inf[i] == ')')
        {
            while (1)
            {
                pop(&s1, &t);
                if (t == '(')
                    break;
                out[j++] = t;
            }
        }
        else // Operator
        {
            if (isEmpty(s1))
                push(&s1, inf[i]);
            else
            {
                pop(&s1, &t);
                if (t == '(')
                {
                    push(&s1, t);
                    push(&s1, inf[i]);
                }
                else
                {
                    if (isLH(t, inf[i]))
                    {
                        push(&s1, t);
                        push(&s1, inf[i]);
                    }
                    else
                    {
                        out[j++] = t;
                        i--;
                    }
                }
            }
        }
        i++;
    }
    while (!isEmpty(s1))
    {
        pop(&s1, &t);
        out[j++] = t;
    }
    out[j] = '\0';
}
void display(char a[])
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        printf("%c", a[i]);
    }
}
int main()
{
    int k;
    char a, b;
    init(&s1);
    char out[100];
    char inf[100] ;
    printf("Enter the infix expression: ");
    scanf("%s", inf);
    
    inf_to_pos(inf, out);
   
    printf("The postfix expression is: ");
    display(out);
}
 