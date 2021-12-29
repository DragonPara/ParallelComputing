#include<stdio.h>
void signalchar_(char *c){
	printf("signal float variable %c\n",*c);
}
void arraychar_(char *c){
	int i;
	printf("array float variables :\n");
	for(i=0;i<10;i++)
		printf("%c\t",c[i]);
	printf("\n");
	c[0]='K';
} 
