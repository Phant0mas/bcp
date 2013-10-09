/*    broadcast copy project
** 
*  This file is part of the bcp project
*
*  Copyright bcp project Contributors
*  (c) 2013.
*  This file is distributed under the terms of the GNU/GPL v3 license.
*  See the folder LICENSE in the root folder of the project for more information.
**/

/*  
    here we declare all the fuction we need to control the program 
    but don't have anything to do with networking 
*/

#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED

#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


int file_exists (char *filename);//checks if file exists on the server side

ssize_t recv_full(int fd, void *buf, ssize_t len);

void sigchld_handler(int s);

#endif
