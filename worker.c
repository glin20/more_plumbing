#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

int main(){
  int file = open("piper", O_RDONLY);
  int file2 = open("pipen", O_WRONLY, 0644);
  while (1){
    char buffer[512] = {'\0'};
    read(file, buffer, sizeof(buffer));
    buffer[strlen(buffer) - 1] = '\0';
    // changes all vowels into l, n, or z.
    for (int i = 0; i < strlen(buffer); i++){
      if (buffer[i] == 'a' | buffer[i] == 'i'){
        buffer[i] = 'l';
      }
      if (buffer[i] == 'e' | buffer[i] == 'u'){
        buffer[i] = 'n';
      }
      if (buffer[i] == 'u'){
        buffer[i] = 'z';
      }
    }
    write(file2, buffer, strlen(buffer));
  }
}
