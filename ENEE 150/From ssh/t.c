#include <stdio.h>

int main(){
	int a;
	printf("enter");
	if(scanf("%d",&a)!=1){	
		fprintf(stderr,"ERRor");
		//printf("%d",a);
	}else {
		printf("You entered a value %d",a);
	}
	
}
