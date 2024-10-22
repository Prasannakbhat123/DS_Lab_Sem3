#include<stdio.h>
#include<string.h>
int isPall(char str[],int start,int end){
	if(start>=end) return 1;
	else if(str[start]!=str[end]) return 0;
	else return isPall(str,start+1,end-1);  
}

void main(){
	char str[100];
	printf("Enter the word: ");
	scanf("%s",str);
	if(isPall(str,0,strlen(str)-1)){
		       	printf("It is a pallindrome");
			}
	else printf("It is not a pallindrome");
}
