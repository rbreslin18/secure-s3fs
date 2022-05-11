# Standalone RC4 Compiling and Running

The standalone rc4 is compatible with OpenSSl no salt encryption decryption and salted encryption
To compile:
	```
  g++ -o rc4 rc4standalone.c -lcrypto
  ```
  Then, once the compilation is successful run the following commands:
  ```
  ./rc4 [key] [infile] [outfile] [optional salt]
  ```
  Key is the key for RC4 used to encrypt and decrypt(These must be the same to decrypt a file)
  Infile is the input file which is to be encrypted
  Outfile is the output which is to be decrypted
  Optional salt will add salt to encryption via the user given salt key (should be 8 bytes)

## S3FS-Fuse Installation
	Cd to s3fs-fuse-master/src
	Run these commands prior to running make file
	
	```
  
	sudo apt install libssl-dev
	sudo apt install libfuse-dev
	sudo apt install libcurl4-openssl-dev
	sudo apt install libxml2-dev
	sudo apt install automake
	sudo apt install autotools-dev
	```
	Cd to s3fs-fuse-master/src

	Then, run these commands after the above packages install.
	
	```
	./autogen.sh
	./configure
	make
	sudo make install
	```
	Then, to mount the file system run the following commands:
	```
	s3fs [nameofs3bucket] [mountpoint]
	```
## Configuration
	The s3fs-fuse file system needs a passwd-s3fs file to know what bucket to go to.
	Run the following command to properly setup the pass-s3fs file
	```
	echo ACCESS_KEY_ID:SECRET_ACCESS_KEY > ${HOME}/.passwd-s3fs
	chmod 600 ${HOME}/.passwd-s3fs
	```
	For encryption on S3FS-Fuse, the no salt key can be defined within the source code. This can be changed in rc4.c in s3fs-fuse-master/src with the H_KEY definition.






## Source Code Used

* [S3FS-Fuse](https://github.com/s3fs-fuse/s3fs-fuse) - S3FS Fuse filesystem used for this project
* [OpenSSL](https://github.com/openssl/openssl) - Open SSL



