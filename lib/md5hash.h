/**
*	This file is part of the bcp project from Jordan Wilberding aka jwilberding
*
* 	This file is distributed under the terms of the GNU/GPL v3 license.
* 	See the file LICENSE folder in the root folder of the project for more information.
**/

#ifndef MD5HASH_H_INCLUDED
#define MD5HASH_H_INCLUDED

#include <stdio.h>

#include <openssl/md5.h>
//we use the openssl md5 library for our purpose 

//generates a md5 hash for a file,returns a character array with that hash
char *md5generate (char *filename) ;


#endif