#include <stdio.h>
#include <string.h>
#define FILE_PATH "test.txt"
int main()
{
    char data[15];
    char *buf = "hello file";
    FILE *fp = fopen(FILE_PATH, "r+");
    if(fp == NULL){
        printf("fopen error!\n");
        return -1;
    }
    size_t chk = fwrite(buf, strlen(buf), 1, fp);
    if(chk < 0){
        printf("fwrit error!\n");
        return -1;
    }
    //光标移至开头，偏移0位
    fseek(fp, 0, SEEK_SET); 
    size_t ret = fread(data, strlen(buf), 1, fp);
    if(ret < 0){
        printf("fread error!\n");
        return -1;
    }
    printf("%s\n", data);
    fclose(fp);
    return 0;
}   

