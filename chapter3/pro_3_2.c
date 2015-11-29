#include "apue.h"
#include <fcntl.h>

char  buf1[] = "abcdefghijklml";
char  buf3[] = "12345678910111213";

int main(){
	int fd;
	if((fd = creat("file_hole.txt", FILE_MODE)) < 0){
		err_sys("create error");
	}
    if(write(fd, buf1, 10) != 10){
        err_sys("write error");
    }

    if(lseek(fd, 10000000000, SEEK_CUR) == -1){
        err_sys("seek fail!");
    }

    if(write(fd, buf3, 15) != 15){
        err_sys("write error!");
    }

}
