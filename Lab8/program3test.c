#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<ctype.h>

#define MAX_SIZE 100

typedef struct Deque{
    char arr[MAX_SIZE];
    int front;
    int rear;
}Deque;

int isEmpty(Deque *dq){
    return dq->front==-1;
}

int isFull(Deque *dq){
    return dq->rear==MAX_SIZE-1;
}

void freeDeque(Deque *dq){
    free(dq);
}

Deque *createDeque(){
    Deque *deque=(Deque *)malloc(sizeof(Deque));
    deque->front=-1;
    deque->rear=-1;
    return deque;
}

void insertRear(Deque *dq,char val){
    if(!isFull(dq)){
        if(dq->rear==-1){
            dq->front=0;
            dq->rear=0;
        }
        else
            dq->rear++;
        dq->arr[dq->rear]=val;
    }
}

char deleteFront(Deque *dq){
    if(!isEmpty(dq)){
        char val=dq->arr[dq->front];
        if(dq->front==dq->rear){
            dq->front=-1;
            dq->rear=-1;
        }
        else
            dq->front++;
        return val;
    }
    return '\0';
}

char deleteRear(Deque *dq){
    if(!isEmpty(dq)){
        char val=dq->arr[dq->rear];
        if(dq->front==dq->rear){
            dq->front=-1;
            dq->rear=-1;
        }
        else
            dq->rear--;
        return val;
    }
    return '\0';
}



int isPallindrome(const char *str){
    Deque *dq=createDeque();
    for(int i=0;str[i]!='\0';i++){
        if(isalnum(str[i])){
            char lowerchar=tolower(str[i]);
            insertRear(dq,lowerchar);
        }
    }
    while(!isEmpty(dq)){
        char frontChar=deleteFront(dq);
        char rearChar=deleteRear(dq);
        if(frontChar!=rearChar){
            freeDeque(dq);
            return 0;
        }
    }
    freeDeque(dq);
    return 1;
}

int main(){
    char str[100];
    printf("Enter a string:");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]=0;
    if(isPallindrome(str))
        printf("It is a pallindrome.\n");
    else
        printf("It is not a pallindrome.\n");
    return 0;
}