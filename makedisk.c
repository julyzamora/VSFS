#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <string.h>

#include "vsfs.h"

int main (int argc, char * argv[])
{
  int n, power, size, ret, i;
  int fd;
  char vdiskname[128];
  int num_blocks = 0;
  if(argc != 3)
  {
    printf("Usage: make_disk <vdiskname> <power2size>\n");
    exit (1);
  }
  strcpy(vdisname, argv[1]);
  power = atoi(argv[2]);
  size = 1 << power;
  num_blocks = size / BLOCKSIZE;
  printf("Disk Name = %s Size = %d Blocks = %d\n",
         vdiskname, size, num_blocks);
  ret = open (vdiskname, O_CREAT | O_RDWR, 0666);
  if(ret == -1)
  {
    printf("Could not create disk...\n");
    exit(1);
  }
  bzero((void *)buf, BLOCKSIZE);
  fd = open(vdiskname, O_RDWR);
  for(i = 0; i < (size / BLOCKSIZE); ++i)
  {
    printf("block=%d\n", i);
    n = write(fd, buf, BLOCKSIZE);
    if(n != BLOCKSIZE)
    {
      printf("write error...\n");
      exit (1);
    }
  }
}