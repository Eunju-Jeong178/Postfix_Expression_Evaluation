//postfix expression evaluation program

#include <stdio.h>
#include <string.h>

#define STACK_SIZE 10
#define EXPR_SIZE 100

int stack[STACK_SIZE];
char expr[EXPR_SIZE];
int pos = 0;
int top = -1;

int eval_postfix();
void push(int item);
int pop();
void print_stack();

int main(void)
{
    printf("Input a postfix expression :");
    fgets(expr, 100, stdin);
    printf("%s\n", expr); // �Է��� ������ �������
    eval_postfix();
}

void push(int item)
{
    if (pos == 1)
    {
        int num;
        num = pop();
        stack[++top] = item + 10 * num;  // ���� ��� sta[0]=3 �̾��ٸ� s[0]=30���� �ٲ��.
    }
    else if (pos == 0)
    {
        stack[++top] = item;
        pos = 1;
    }
   print_stack();
}

int pop()
{
    return(stack[top--]);
}

int eval_postfix()
{
    char sym;
    int i = 0, op1, op2;

    while ((sym = expr[i++]) != '\n')  // ������ ������ �ݺ�
    {
        if (isdigit(sym))   // 0~9�� �����̸� 0�� �ƴ� ���� ��ȯ. �׷��� ������ 0�� ��ȯ.
            push(sym - '0');
        else if (sym == ' ')  // �����̽� ��
            pos = 0;
        else  // ������(+,-,*,/)
        {
            pos = 0;
            op2 = pop();
            op1 = pop();
            switch (sym)
            {
            case '+':push(op1 + op2); break;
            case '-':push(op1 - op2); break;
            case '*':push(op1 * op2); break;
            case '/':push(op1 / op2); break;
            case '%':push(op1 % op2); break;
            default: break;
            }
        }
    }
    return 0;
}

void print_stack()
{
    int i;
    printf("[STACK] ");
    for (i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}
