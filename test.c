#include <stdio.h>
#include <stdlib.h>

/* To shorten example, not using argp */
int main (int argc, char *argv[], char *envp[])
{
  char *home, *host;

  home = getenv("PATH");
  host = getenv("LOGNAME");

  printf ("Your home directory is %s\n on %s.\n", home, host);

  return 0;
}