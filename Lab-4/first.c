#include<stdio.h>
#include<stdlib.h>
struct Complex{
	float real,imag;
};
struct Complex addComplex(struct Complex *c1,struct Complex *c2){
	struct Complex result;
	result.real=c1->real+c2->real;
	result.imag=c1->imag+c2->imag;
	return result;
}
struct Complex subComplex(struct Complex *c1,struct Complex *c2){
	struct Complex result;
	result.real=(c1->real)-(c2->real);
	result.imag=c1->imag-c2->imag;
	return result;
}
struct Complex mulComplex(struct Complex *c1,struct Complex *c2){
	struct Complex result;
	result.real=c1->real*c2->real-c1->imag*c2->imag;
	result.imag=c1->real*c2->imag+c1->imag*c2->real;
	return result;
}
int main(){
	struct Complex c1,c2,result;
	printf("Enter real and imaginary part of first Complex number:\n");
	scanf("%f %f",&c1.real,&c1.imag);
	printf("Enter real and imaginary part of second Complex number:\n");
	scanf("%f %f",&c2.real,&c2.imag);
	result=addComplex(&c1,&c2);
	printf("Addition:%2f+%2fi\n",result.real,result.imag);
	result=subComplex(&c1,&c2);
	result=subComplex(&c1,&c2);
	printf("Subtraction:%2f+%2fi\n",result.real,result.imag);
	result=mulComplex(&c1,&c2);
	printf("Multiplication:%2f+%2fi\n",result.real,result.imag);
	return 0;
}
