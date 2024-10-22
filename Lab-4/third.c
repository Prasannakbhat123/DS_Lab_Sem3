#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct date{
	int day,month,year;
};
struct address{
	int house_no,zip;
	char state[50];
};
struct employee{
	char name[100];
	struct date dob;
        struct address add;
};
void readEmployee(struct employee *emp){
	printf("\nEnter name: ");
	scanf("%s",emp->name);
	printf("Enter date of birth (dd mm yyyy):");
	scanf("%d %d %d",&emp->dob.day,&emp->dob.month,&emp->dob.year);
	printf("Enter Address (house number, zip code, state): ");
	scanf("%d %d %s",&emp->add.house_no,&emp->add.zip,emp->add.state);
}
void displayEmployee(struct employee *emp){
	printf("\nName: %s",emp->name);
	printf("\nDate of birth: %d-%d-%d",emp->dob.day,emp->dob.month,emp->dob.year);
	printf("\nAddress: %d,%d,%s",emp->add.house_no,emp->add.zip,emp->add.state);
}
int main(){
	int n;
	printf("\nEnter the number of Employees: ");
	scanf("%d",&n);
	struct employee *employees=(struct employee *)malloc(n*sizeof(struct employee));
	for(int i=0;i<n;i++){
		printf("\nEnter the details for Employee %d:",i+1);
		readEmployee(&employees[i]);
	}
	printf("\nDisplaying Employee details:");
	for(int i=0;i<n;i++)
		displayEmployee(&employees[i]);
	free(employees);
	return 0;
}


