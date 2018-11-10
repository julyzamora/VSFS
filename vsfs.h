#ifndef VSFS_H
#define VSFS_H

#define BLOCKSIZE 4096
#define MAXFILECOUNT 128
#define MAXDISKSIZE (1 << 28)
#define MINDISKSIZE (1 << 20)
#define MAXFILENAMESIZE 128
#define MAXBLOCKCOUNT (MAXDISKSIZE / BLOCKSIZE)
#define MAXOPENFILES 128
#define MAXREADWRITE 1024


int vsfs_format(char * vdisk, int dsize);


int vsfs_mount(char *vdisk);
int vsfs_unmount();
int vsfs_create();
int vsfs_open(char * filename);
int vsfs_close(int fd); // file descriptor
int vsfs_delete(char * filename);
int vsfs_read(int fd, void * buf, int n);
int vsfs_write(int fd, void *buf, int n);
int vsfs_truncate(int fd, int size);
int vsfs_seek(int fd, int offset);
void vsfs_print_dir ();
void vsfs_print_fat ();

//TODO implement a fast file system using locality

#endif