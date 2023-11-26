// vim /usr/src/kernels/linux-4.16.9/Documentation/ioctl/ioctl-number.txt


#ifndef MAGIC
#define MAGIC 'k'
#endif

#ifndef RESET
#define RESET _IO(MAGIC,1)
#endif

#ifndef GET_DEV
#define GET_DEV _IOR(MAGIC,2,int)
#endif

#ifndef NO_OF_REG
#define NO_OF_REG _IOW(MAGIC,3,int)
#endif

#ifndef REG_SIZE
#define REG_SIZE _IOW(MAGIC,4,int)
#endif

#ifndef DATA_SIZE
#define DATA_SIZE _IOW(MAGIC,5,int)
#endif

#ifndef DEV_SIZE
#define DEV_SIZE _IOW(MAGIC,6,int)
#endif



