#include <stdio.h>

int main(int argc, char **argv) {
	int text;
	
	//if (argc>1){  	
	while ((text = fgetc(stdin)) != EOF) {
		printf("%02x", text);
	}	
	
	//else {
	//	printf("%s\n","invalid input");}
	return 0;
}
