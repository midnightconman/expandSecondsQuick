
#include <stdlib.h>
#include <time.h>

#include "expandSeconds.h"
#include "main.h"

int main (int argc, char **argv) {

srand48(time(NULL));

size_t i = 0;

while(i <= 149999) {

  char *s = malloc (1);
  s = expandSeconds(s, (int)lrand48());
  printf("%s\n", s);
  free(s);

i++;
}

  return(0);

}
