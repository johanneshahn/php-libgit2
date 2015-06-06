# php-libgit2
self wrapped libgit2 with phpcpp

#required libs
libgit2
phpcpp

-> see Makefile


#build
make;

#testing on command line
$ php -c php-libgit2.ini -f test.php

Error Message: Unable to load dynamic library '.../php-libgit2.so' - libgit2.so.xx
!!! check that libgit2.so can be found before exec
$ echo $LD_LIBRARY_PATH
... should output the path where libgit2.so can be found
/usr/local/lib

or if empty
$ locate libgit2.so
