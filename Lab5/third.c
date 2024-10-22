#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    int top;
    char items[MAX];
} Stack;

void push(Stack *s, char val) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        s->items[++(s->top)] = val;
    }
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return s->items[(s->top)--];
    }
}

int isPalindrome(char str[]) {
    Stack s;
    s.top = -1;
    int length = strlen(str);
    
    for (int i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
   
    for (int i = 0; i < length; i++) {
        push(&s, str[i]);
    }
    
    for (int i = 0; i < length; i++) {
        if (str[i] != pop(&s)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[MAX];
    
    printf("Enter a string: ");
    scanf("%s",str);
    
    if (isPalindrome(str)) {
        printf("The string is a palindrome\n");
    } else {
        printf("The string is not a palindrome\n");
    }
    
    return 0;
}

