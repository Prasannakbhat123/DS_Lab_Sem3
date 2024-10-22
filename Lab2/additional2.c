#include<stdio.h>
#include<string.h>
void reverse(char str[],int start,int end){
	if(start>=end) return;
	char temp;
	temp=str[start];
	str[start]=str[end];
	str[end]=temp;
	reverse(str,start+1,end-1);
}

void main(){
	char str[100];
	printf("Enter a string: ");
	scanf("%s",str);
	reverse(str,0,strlen(str)-1);
	printf("After reversing: %s",str);
}
