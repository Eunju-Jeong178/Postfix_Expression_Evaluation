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
    printf("%s\n", expr); // 입력한 수식을 출력해줌
    eval_postfix();
}

void push(int item)
{
    if (pos == 1)
    {
        int num;
        num = pop();
        stack[++top] = item + 10 * num;  // 예를 들어 sta[0]=3 이었다면 s[0]=30으로 바뀐다.
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

    while ((sym = expr[i++]) != '\n')  // 수식의 끝까지 반복
    {
        if (isdigit(sym))   // 0~9의 숫자이면 0이 아닌 값을 반환. 그렇지 않으면 0을 반환.
            push(sym - '0');
        else if (sym == ' ')  // 스페이스 바
            pos = 0;
        else  // 연산자(+,-,*,/)
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
