# Two methods of the bin2ascii conversion

The purpose was to display ECC EK certificate in the
readable format. To try to retrieve part of EK public key
and tpm 2.0 silicon manufacturer.

Still do not know if there are some special tools for this
purpose, bin2ascii also suppose to serve as general one.

## inout_bin2ascii/ (bin2ascii via <input_file> to <output_file>)

This is a classical way how to convert <input_file> to <output_file>

### Compiling/linking command

	$ gcc bin2ascii.c -o bin2ascii

Also the alternative:

	$ make

### Creating <output_file.ascii>

	$ ./bin2ascii <input_file.bin> <output_file.ascii>
	$ hexdump -C <output_file.ascii>
	$ cat <output_file.ascii>

### Example: Retrieve ECC_EK_cert.bin to ECC_EK_cert.ascii

#### [Optional] Retrieve Public part of TMP2 Endorsement Key

	## TMP2 Endorsement Key (EK)
	## Retrieve multiple EK certificates from TPM2 NV indices only, fail otherwise
	## tpm2_getekcertificate -o RSA_EK_cert.bin -o ECC_EK_cert.bin

#### ./bin2ascii ECC_EK_cert.bin ECC_EK_cert.ascii

	$ ./bin2ascii ECC_EK_cert.bin ECC_EK_cert.ascii
	$ hexdump -C ECC_EK_cert.ascii
	$ cat ECC_EK_cert.ascii

## mmap_bin2ascii/ (bin2ascii via mmap())

### Compiling/linking command

	$ gcc bin2ascii.c -o bin2ascii

Also the alternative:

	$ make

### Creating <output_file.ascii>

	$ ./bin2ascii <input_file.bin> > <output_file.ascii>
	$ hexdump -C <output_file.ascii>
	$ cat <output_file.ascii>

### Example: Retrieve ECC_EK_cert.bin to ECC_EK_cert.ascii

#### [Optional] Retrieve Public part of TMP2 Endorsement Key

	## TMP2 Endorsement Key (EK)
	## Retrieve multiple EK certificates from TPM2 NV indices only, fail otherwise
	## tpm2_getekcertificate -o RSA_EK_cert.bin -o ECC_EK_cert.bin

#### ./bin2ascii ECC_EK_cert.bin > ECC_EK_cert.ascii

	$ ./bin2ascii ECC_EK_cert.bin > ECC_EK_cert.ascii
	$ hexdump -C ECC_EK_cert.ascii
	$ cat ECC_EK_cert.ascii

