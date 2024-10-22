#include<stdio.h>
void copyString(char ch1[],char ch2[], int i){
	if(ch1[i]=='\0'){
		ch2[i]='\0';
		return;
	}

	ch2[i]=ch1[i];
	copyString(ch1,ch2,i+1);
}

void main(){
	char ch1[100],ch2[100];
	printf("Enter the string: ");
	scanf("%s",ch1);
	copyString(ch1,ch2,0);
	printf("String after copying: %s",ch2);
	}
