#include<stdio.h>
void signalint_(int *c){
	printf("signal integer variable %d\n",*c);
}
void arrayint_(int *c){
	int i;
	printf("array integer variables :\n");
	for(i=0;i<10;i++)
		printf("%d\t",c[i]);
	printf("\n");
	c[0]=1234;
} 
