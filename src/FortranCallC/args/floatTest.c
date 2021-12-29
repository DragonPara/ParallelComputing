#include<stdio.h>
void signalfloat_(float *c){
	printf("signal float variable %g\n",*c);
}
void arrayfloat_(float *c){
	int i;
	printf("array float variables :\n");
	for(i=0;i<10;i++)
		printf("%g\t",c[i]);
	printf("\n");
	c[0]=12.34;
} 
