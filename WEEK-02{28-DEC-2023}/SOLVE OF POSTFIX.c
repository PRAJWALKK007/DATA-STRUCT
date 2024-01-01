#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int item)
{
    if (top >= MAX - 1)
        {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

int pop()
{
    if (top < 0)
        {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int evaluate_postfix(char postfix[])
{
    int i, operand1, operand2, result;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++)
        {
        ch = postfix[i];
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            operand2 = pop();
            operand1 = pop();
            switch (ch)
            {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid Expression\n");
                    exit(1);
            }
            push(result);
        }
    }
    return pop();
}

int main()
{
    char postfix[MAX];
    printf("Enter postfix expression: ");
    gets(postfix);
    int result = evaluate_postfix(postfix);
    printf("Result: %d\n", result);
    return (0);
}