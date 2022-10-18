#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int isHL(char a, char b)
{
    if (getv(a) > getv(b))
        return 1;
    else
        return 0;
}
void rev(char *a)
{
    int i, j;
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == '(')
        {
            a[i] = ')';
        }
        else if (a[i] == ')')
        {
            a[i] = '(';
        }
    }
    for (i = 0, j = strlen(a) - 1; i < j; i++, j--)
    {
        a[i] = a[i] ^ a[j] ^ (a[j] = a[i]);
        // int flag = 0;
        // if (a[i] == '(')
        // {
        //     a[i] = ')';
        //     flag = 1;
        // }
        // if (a[i] == ')' && flag == 0)
        // {
        //     a[i] = '(';
        // }
        // if (a[j] == '(')
        // {
        //     flag = 1;
        //     a[j] =')';
        // }
        // if (a[j] == ')' && flag == 0)
        // {
        //     a[j] = '(';
        // }
    }

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
                        if (isHL(t, inf[i])) // changed
                        {
                            out[j++] = t;
                            i--;
                        }
                        else
                        {
                            push(&s1, t);
                            push(&s1, inf[i]);
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
        init(&s1);
        char out[100];
        char inf[100];
        printf("Enter the infix expression: ");
        scanf("%s", inf);
        rev(inf);
        inf_to_pos(inf, out);
        rev(out);

        printf("The prefix expression is: ");
        display(out);
    }
