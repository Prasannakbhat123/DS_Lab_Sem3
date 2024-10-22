#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Dob{
	int day;
	int month;
	int year;
};
struct Stu_info{
	int reg_no;
	char *name;
	char *add;
};
struct College{
	char *college_name;
	char *university_name;
};
struct student{
	struct Dob *dob;
	struct Stu_info *stu_info;
        struct College *college;
};
void readStudent(struct student *stu){
	stu->dob=(struct Dob*)malloc(sizeof(struct Dob));
	stu->stu_info=(struct Stu_info*)malloc(sizeof(struct Stu_info));
	stu->college=(struct College*)malloc(sizeof(struct College));
	stu->stu_info->name=(char*)malloc(10*sizeof(char));
	stu->stu_info->add=(char*)malloc(20*sizeof(char));
	stu->college->college_name=(char*)malloc(20*sizeof(char));
	stu->college->university_name=(char*)malloc(20*sizeof(char));
	printf("\nEnter date of birth (dd mm yyyy):");
	scanf("%d %d %d",&stu->dob->day,&stu->dob->month,&stu->dob->year);
	printf("\nEnter registration number:");
	scanf("%d",&stu->stu_info->reg_no);
	printf("\nEnter name:");
	scanf("%s",stu->stu_info->name);
	printf("Enter address:");
	scanf("%s",stu->stu_info->add);
	printf("Enter College name:");
	scanf("%s",stu->college->college_name);
	printf("Enter University name:");
	scanf("%s",stu->college->university_name);
}
void displayStudent(struct student *stu){
	printf("\nDate of Birth: %d-%d-%d",stu->dob->day,stu->dob->month,stu->dob->year);
        printf("\nRegistration number: %d",stu->stu_info->reg_no);
	printf("\nName: %s",stu->stu_info->name);
	printf("\nAddress: %s",stu->stu_info->add);
	printf("\nCollege: %s",stu->college->college_name);
	printf("\nUniversity: %s",stu->college->university_name);
}
int main(){
	int n;
	printf("Enter the number of Stduents:");
	scanf("%d",&n);
	struct student *stu=(struct student *)malloc(n*sizeof(struct student));
	for(int i=0;i<n;i++){
		printf("\nEnter details for student %d",i+1);
		readStudent(&stu[i]);
	}
	for(int i=0;i<n;i++){
		printf("\nInfo of Student %d",i+1);
		displayStudent(&stu[i]);
	}
	return 0;
}
