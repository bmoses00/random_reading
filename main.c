# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include "random_number.h"

int main() {
  int ARR_SIZE = 10;
  int arr[ARR_SIZE], finalArr[ARR_SIZE];
  int fd, b, i;

  printf("Generating random numbers:\n");
  for (i = 0; i < ARR_SIZE; i++) {
    arr[i] = random_number();
    if (arr[i] == -1) {
      printf("Error %d: %s\n", errno, strerror(errno));
      return -1;
    }
  }

  for (i = 0; i < ARR_SIZE; i++) {
    printf("el %d: %d\n", i, arr[i]);
  }

  printf("\nWriting numbers to file...\n\n");
  fd = open("rand", O_CREAT|O_EXCL|O_WRONLY, 0755);
  if (fd == -1) {
    fd = open("rand", O_WRONLY);
  }
  b = write(fd, arr, ARR_SIZE * sizeof(int));
  if (b == -1) {
    printf("Error %d: %s\n", errno, strerror(errno));
    return -1;
  }
  close(fd);

  printf("Reading numbers from file...\n\n");
  fd = open("rand", O_RDONLY);
  b = read(fd, finalArr, ARR_SIZE * sizeof(int));
  b = close(fd);
  if (b == -1) {
    printf("Error %d: %s\n", errno, strerror(errno));
    return -1;
  }

  printf("Verification that written values were the same: \n");
  for (i = 0; i < ARR_SIZE; i++) {
    printf("el %d: %d\n", i, finalArr[i]);
  }
}
