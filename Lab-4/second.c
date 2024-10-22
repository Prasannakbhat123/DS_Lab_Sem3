#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student{
	int roll_no;
	char *name;
	float CGPA;
};
void readStudent(struct Student *stu){
	char buffer[100];
	printf("\nEnter name: ");
	scanf("%s",buffer);
	stu->name=(char *)malloc(strlen(buffer)+1);
	strcpy(stu->name,buffer);
	printf("Enter roll number:");
	scanf("%d",&stu->roll_no);
	printf("Enter CGPA:");
	scanf("%f",&stu->CGPA);
}
void displayStudent(struct Student *stu){
	printf("\nName: %s",stu->name);
	printf("\nRoll Number: %d",stu->roll_no);
	printf("\nCGPA: %2f",stu->CGPA);
}
void sortStudent(struct Student *stu,int n){
	struct Student temp;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(stu[i].roll_no>stu[i].roll_no){
				temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
			}
		}
	}
}

int main(){
	int n;
	printf("\nEnter the number of Students:");
	scanf("%d",&n);
	struct Student *students=(struct Student *)malloc(n*sizeof(struct Student));
	for(int i=0;i<n;i++){
		printf("\nEnter details of Student %d:",i+1);
		readStudent(&students[i]);
	}
	sortStudent(students,n);
	printf("\nStudent list after sorting: ");
	for(int i=0;i<n;i++){
		displayStudent(&students[i]);
	}
	for(int i=0;i<n;i++)
		free(students[i].name);
	free(students);
	return 0;
}
