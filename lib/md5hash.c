/**
*	This file is part of the bcp project from Jordan Wilberding aka jwilberding
*
* 	This file is distributed under the terms of the GNU/GPL v3 license.
* 	See the file LICENSE folder in the root folder of the project for more information.
**/

#include "md5hash.h"

//generates a md5 hash for a file,returns a character array with that hash
char *md5generate (char *filename)
{
	unsigned char c[MD5_DIGEST_LENGTH];//the hash will be saved here in hex form
	int i;
	FILE *inFile = fopen (filename, "rb");
    MD5_CTX mdContext;
    int bytes;
    unsigned char data[1024];

    //if there is an error opening the file exit with code -1
    if (inFile == NULL) {	
        printf ("%s can't be opened.\n", filename);
        exit(-1);
    }
    //starts generating the hash
 	MD5_Init (&mdContext);
    while ((bytes = fread (data, 1, 1024, inFile)) != 0)
        MD5_Update (&mdContext, data, bytes);
    MD5_Final (c,&mdContext);
    //the hash is saved in the array named c

    for(i = 0; i < MD5_DIGEST_LENGTH; i++) 
    	printf("%02x", c[i]); //prints the hash
    // printf (" %s\n", filename); //prints the filename
    
    fclose (inFile);

    return c;

}