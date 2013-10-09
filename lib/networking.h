/*    broadcast copy project
** 
*  This file is part of the bcp project
*
*  Copyright bcp project Contributors
*  (c) 2013.
*  This file is distributed under the terms of the GNU/GPL v3 license.
*  See the LICENSE in the root folder of the project for more information.
**/



#ifndef NETWORKING_H_INCLUDED 
#define NETWORKING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <libgen.h>

#include "control.h"

#define BROADCAST_PORT 4950   // default udp port
#define BCP_CODE 3141593      // have a unique code to verify broadcast
#define BCP_TCP_PORT 10789    // default tcp port
#define BACKLOG 10            // how many pending connections queue will hold
#define MAXBUFLEN 1024        // buffer size for packets
#define MAXNAMELEN 255        // max filename length


void listener(char *ip, int *port);//looking for a server to send the file

void client(char *ip, int *port, char *path);//sends the file

void server(int port);//receives file

void broadcaster();

void *get_in_addr(struct sockaddr *sa);// get sockaddr, IPv4 or IPv6:

#endif
