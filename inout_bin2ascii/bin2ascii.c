/*
 * bin2ascii.c
 * Copy the contents of one file to another
 * file, using memory mappings.
 * Usage bin2ascii <input_file> <output_file>
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (3 != argc) {
		fprintf(stderr, "%s <binaryFile> <asciiFile>\n", argv[0]);
		exit(1);
	}

	FILE *binaryFile = fopen(argv[1], "rb");  // Open binary file for reading
	FILE *asciiFile = fopen(argv[2], "w");    // Open ASCII file for writing

	if ((NULL == binaryFile) || (NULL == asciiFile)) {
		printf("Error opening files!");
		return 1;
	}

	int	byte;
	char	asciiSymbol;
	while ((byte = fgetc(binaryFile)) != EOF) {
		// Convert each byte to its 7-bit ASCII representation
		// print only all visible ascii characters
		if ((0x20 > byte) || (0x7e < byte))
			asciiSymbol = '.';
		else
			// Keep only the lowest 7 bits
			asciiSymbol = byte & 0x7F; 

		// Write the ASCII symbol to the file
		fprintf(asciiFile, "%c", asciiSymbol);
	}

	fclose(binaryFile);
	fclose(asciiFile);

	printf("Binary file %s converted to ASCII file %s successfully!\n", argv[1], argv[2]);

	return 0;
}
