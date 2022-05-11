#include <iostream>
#include <openssl/rc4.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <rc4.h>
#include <ctype.h>
#define H_KEY "hello"
#define NUM_SALT 8
using namespace std;
void rc4::rc4File(int fd, char input){
    off_t filesize;
    RC4_KEY key;// Declare RC4 Key
    unsigned char key_buffer[16];
    filesize = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    printf("Filesize is %li\n",filesize);
    unsigned char* inbuff = (unsigned char*)malloc(filesize);
    unsigned char* outbuff = (unsigned char*)malloc(filesize);
    static const char magic[] = "Salted__";
    unsigned char *salt;
    RAND_bytes(salt, NUM_SALT);
    printf("Here is salt: %s\n",salt);

    read(fd, inbuff, filesize);
    printf("Here is the buffer:\n");
    printf("%hhn\n",inbuff);
    switch(input){
        case 'E': //No Salt encryption
        if (EVP_BytesToKey(EVP_rc4(), EVP_sha256(), NULL,
                     (const unsigned char *)H_KEY, strlen(H_KEY), 1,
                     key_buffer, NULL) != 16) {
                         fputs("Error calculating rc4 key!\n", stderr);
                     }
        RC4_set_key(&key,sizeof(H_KEY),(const unsigned char*)H_KEY);
        RC4(&key,filesize,inbuff,outbuff);
        lseek(fd,0,SEEK_SET);
        // write(fd,outbuff,filesize);
        break;

        case 'S':

        break;

        case 'D':

        break;

        default:
        break;
        
    }
   
    free(inbuff);
    free(outbuff);



}