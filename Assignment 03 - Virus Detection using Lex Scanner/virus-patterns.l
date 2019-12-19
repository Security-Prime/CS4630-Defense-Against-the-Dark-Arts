%{
#include <stdio.h>

int byteNum = 0;

%}

%%


68[0-9a-f]{8}c3 {
	printf("WARNING! Tricky Jump: byte number: %#08x \n", byteNum);
	printf("%s \n", yytext);
	byteNum += 6;	
}
bc[0-9a-f]{8}31[0-9]{2}31[0-9]{2} {
	printf("WARNING! Cavalier Virus: byte number: %#08x \n", byteNum);
	printf("%s \n", yytext);
	byteNum += 9;	
}
89[0-9a-f]{2}50583b[0-9a-f]{4} {
	printf("WARNING! Rotunda Virus: byte number: %#08x \n", byteNum);
	printf("%s \n", yytext);
	byteNum += 7;
}

.. {
byteNum ++; 
}

%%

int main() {
	yylex();
	return 0;
}
