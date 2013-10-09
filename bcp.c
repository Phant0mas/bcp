/*
** bcp.c -- broadcast copy -- Jordan Wilberding -- (C) 2012-2013

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

  See the folder LICENSE in the root folder of the project for more information.
*/

#include <stdio.h>
#include <unistd.h>

#include "lib/control.h"
#include "lib/networking.h"


int main(int argc, char *argv[])
{
  int port;
  char ip[INET6_ADDRSTRLEN];

  if (argc > 1) {
    printf("Listening for request..\n");
    listener(ip, &port);
    printf("Sending file to: %s:%d\n", ip, port);
    client(ip, &port, argv[1]);
  }
  else {
    printf("Requesting file..\n");
    if (!fork()) { // this is the child process
      server(BCP_TCP_PORT);
    }
    else {
      sleep(1);
      broadcaster();
      int status;
      wait(&status);
    }
  }

  return 0;
}
