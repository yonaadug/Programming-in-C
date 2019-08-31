#include <stdio.h>

int main(){

	void *p;
	int i=0;
	for(i; i<1000; i++){
		printf("%s", &p++);
	}
	
	return 0;

}

