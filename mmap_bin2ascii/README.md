## bin2ascii

This creation was done as a quick hack, since I was not
satisfied with the other bin2hex, bin2txt and similar
tools found on the net/github.

The purpose was to display ECC EK certificate in the
readable format. To try to retrieve part of EK public key
and tpm 2.0 silicon manufacturer.

Still do not know if there are some special tools for this
purpose, bin2ascii also suppose to serve as general one.

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

#### ECC_EK_cert.ascii

0..J0..........\..N0...*.H.=...0v1.0...U....DE1!0...U....Infineon Technologies AG1.0...U....OPTIGA(TM)1/0-..U...&Infineon OPTIGA(TM) TPM 2.0 ECC CA 0610...221110202750Z..371110202750Z0.0Y0...*.H.=....*.H.=....B......G|.<<hs.....j.a...A.S............1s.\.iL.4..eO....C...^.........0...0\..+........P0N0L..+.....0..@https://pki.infineon.com/OptigaEccMfrCA061/OptigaEccMfrCA061.crt0...U...........0X..U......N0L.J0H1.0...g......id:494658001.0...g......SLB 9672 TPM2.01.0...g......id:0F160...U.......0.0Q..U...J0H0F.D.B.@https://pki.infineon.com/OptigaEccMfrCA061/OptigaEccMfrCA061.crl0...U. ..0.0...*...D...0...U.#..0...V.....2.<.42!..}.n..0...U.%..0...g....0"..U....0.0...g....1.0...2.0.......0...*.H.=.......0...B.&d++.O.....<Y&z....:rK.2.Cf.A...#.KR..pH/.<"..e...k....H....V+....B..e.....z..'CM.......K...M4c..'.q..P.........A=...$...o...........
