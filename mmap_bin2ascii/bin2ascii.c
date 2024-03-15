/*
 * bin2ascii.c
 * Copy the contents of one file to another
 * file, using memory mappings.
 * Usage bin2ascii <input_file> > <output_file>
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int	fdSrc;

	if (argc != 2) {
		fprintf(stderr, "%s source-file \n", argv[0]);
		exit(1);
	}

	if (-1 == (fdSrc = open(argv[1], O_RDONLY))) {
		perror("open file failed, src_fd = -1");
		exit(1);
	}

	// Use fstat() to obtain size of file: we use this
	// to specify the size of the two mappings
	struct stat sb;
	if (-1 == fstat(fdSrc, &sb)) {
		perror("fstat failed");
		printf("fstat failed, &sb = %p\n", &sb);
		exit(1);
	}

	// Handle zero-length file specially, since specifying a size
	// of zero to mmap() will fail with the error EINVAL
	if (0 == sb.st_size) {
		perror("sb.st_size is 0");
		printf("sb.st_size is %d\n", sb.st_size);
		exit(EXIT_SUCCESS);
	}

	char *src = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fdSrc, 0);
	if (MAP_FAILED == src) {
		perror("mmap from fdSrc to src copying failed");
		printf("mmap from fdSrc = %d to src = %p copying failed\n", fdSrc, src);
		exit(1);
	}

	for (int i=0; i < sb.st_size; i++) {
		// print only all visible ascii characters
		if ((0x20 > src[i]) || (0x7e < src[i]))
			printf(".");
		else
			printf("%c", src[i]);
	}
	printf("\n");

	if (-1 == munmap(src, sb.st_size))
		printf("munmap src failed, src = %p\n", src);

	if (-1 == close(fdSrc)) {
		perror("closing the fdSrc file failed");
		printf("closing the fdSrc file failed, fdSrc = %d\n", fdSrc);
		exit(1);
	}

	exit(EXIT_SUCCESS);
}
