#include<stdio.h>
void capital(char str[100],int i){
	if(str[i]=='\0'){
		printf("\nNo capital leter found");
		return;
	}
	if(str[i]>='A'&&str[i]<'Z'){
		printf("\nFirst capital letter= %c",str[i]);
		return;
	}
	capital(str,i+1);
}

void main(){
	char str[100];
	printf("Enter a string: ");
	scanf("%s",str);
	capital(str,0);
}
