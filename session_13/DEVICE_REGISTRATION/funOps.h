
struct file_operations fops={

	open:	openMyDev,	// do read IMPORTANT comment in declaration.h
	release:	releaseMyDev,	// do read IMPORTANT comment in declaration.h	
	read:	readMyDev,
	write:	writeMyDev,
	llseek: lseekDev,
};
