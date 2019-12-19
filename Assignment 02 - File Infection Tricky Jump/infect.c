//fr2md
#include <stdio.h> 
#include <stdlib.h>

 int main(void) { 
     FILE *in;
     FILE *out;
     char *buffer;
     int size;
     in = fopen("target.exe", "rb");
     fseek(in, 0, SEEK_END);
     size = ftell(in);
     fseek(in, 0, SEEK_SET);
     buffer = malloc(size);
//reading from target
     fread(buffer, 1, size, in);

// Starting to change the file after the leave command in Initialize mode
//push ebp
	buffer[0x44d] = 0x90;	
	buffer[0x44e] = 0x55;
//mov esp ebp
	buffer[0x44f] = 0x89;
	buffer[0x450] = 0xe5;
//sub 18 esp
	buffer[0x451] = 0x83;
	buffer[0x452] = 0xec;
	buffer[0x453] = 0x18;
//movl the address of 'W' to esp
	buffer[0x454] = 0xc7;
	buffer[0x455] = 0x04;
	buffer[0x456] = 0x24;
	buffer[0x457] = 0x62;
	buffer[0x458] = 0x84;
	buffer[0x459] = 0x04;
	buffer[0x45a] = 0x08;
//call puts@plt to print
	buffer[0x45b] = 0xe8;
	buffer[0x45c] = 0x84;
	buffer[0x45d] = 0xfe;
	buffer[0x45e] = 0xff;
	buffer[0x45f] = 0xff;
	buffer[0x460] = 0xc9;
	buffer[0x461] = 0xc3;
//payload
	buffer[0x462] = 'W';
	buffer[0x463] = 'a';
	buffer[0x464] = 'h';
	buffer[0x465] = 'o';
	buffer[0x466] = 'o';
	buffer[0x467] = ' ';
	buffer[0x468] = 'v';
	buffer[0x469] = 'i';
	buffer[0x46a] = 'r';
	buffer[0x46b] = 'u';
	buffer[0x46c] = 's';
	buffer[0x46d] = ' ';
	buffer[0x46e] = 'a';
	buffer[0x46f] = 'c';
	buffer[0x470] = 't';
	buffer[0x471] = 'i';
	buffer[0x472] = 'v';
	buffer[0x473] = 'a';
	buffer[0x474] = 't';
	buffer[0x475] = 'e';
	buffer[0x476] = 'd';
	buffer[0x477] = '!';
	buffer[0x478] = ':';
	buffer[0x479] = 'D';
	buffer[0x47a] = 0x00;

     fclose(in);
//Writing to a new file
     out = fopen("infectedTarget.exe", "wb");
     fwrite(buffer, 1, size, out);
     fclose(out);
 }
