#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

int main(){
  printf("Creating pipes...\n");
  int i = mkfifo("piper", 0666);
  int j = mkfifo("pipen", 0666);
  if ((i || j) && errno != EEXIST){
    printf("Error: %s\n", strerror(errno));
  }
  else{
    if (errno == EEXIST){
      printf("Pipes already exist\n");
    }
    else {
      printf("Made pipes\n");
    }
    int file = open("piper", O_WRONLY, 0644);
    int file2 = open("pipen", O_RDONLY);
    while (1){
      char buffer[512];
      fgets(buffer, sizeof(buffer), stdin);
      buffer[strlen(buffer) - 1] = '\0';
      write(file, buffer, strlen(buffer));
      read(file2, buffer, sizeof(buffer));
      printf("%s\n", buffer);
    }
  }
}
