#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char data[MAX][MAX];
    int top;
} stack;

void init(stack *s) {
    s->top = -1;
}

int isEmpty(stack *s) {
    return s->top == -1;
}

int isFull(stack *s) {
    return s->top == MAX - 1;
}

void push(stack *s, const char *str) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    strcpy(s->data[++(s->top)], str);
}

char* pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void prefixToPostfix(const char *prefix, char *postfix) {
    stack s;
    init(&s);
    int length = strlen(prefix);
    for (int i = length - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            char operand[2] = {prefix[i], '\0'};
            push(&s, operand);
        } else if (isOperator(prefix[i])) {
            char op1[MAX], op2[MAX];
            strcpy(op1, pop(&s));
            strcpy(op2, pop(&s));
            char temp[MAX];
            snprintf(temp, sizeof(temp), "%s%s%c", op1, op2, prefix[i]);
            push(&s, temp);
        }
    }
    strcpy(postfix, pop(&s));
}

int main() {
    char prefix[MAX], postfix[MAX];
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);
    prefixToPostfix(prefix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

