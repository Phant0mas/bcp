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
    here we have all the fuction we need to control the program 
    but don't have anything to do with networking 
*/

int file_exists (char *filename)//checks if file exists on the server side
{
  struct stat buffer;
  return (stat (filename, &buffer) == 0);
}

ssize_t recv_full(int fd, void *buf, ssize_t len)
{
  char *p = buf;
  ssize_t recvd;
  for (recvd = 1; len > 0 && recvd > 0; len -= recvd, p += recvd)
    recvd = recv(fd, p, len, 0);
  return p - (char *)buf;
}

