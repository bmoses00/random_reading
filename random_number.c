# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

int random_number() {
  int buff[1];
  int fd, b;
  fd = open("/dev/random", O_RDONLY);
  b = read(fd, buff, sizeof(int));
  if (b == -1)
    return -1;
  else
    return * buff;
}
