/*
 * expandSeconds - A simple C library that takes a char* and an unsigned int
 *                 of seconds and converts that to weeks,days,hours,mins,secs
 *
 * Written by:   Jon Campbell
 * Date:         07/18/2013
 *
 *
 */


#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "expandSeconds.h"

char *expandSeconds (char *c, int seconds) {

  int w = 0;
  int d = 0;
  int h = 0;
  int m = 0;
  int s = 0;

  c[0] = '\0';

  w = (seconds / 604800);
  if (w != 0) {
    if (1 == w) {
      c = strConcat (c, "%s%i week ", c, w);
    } else {
      c = strConcat (c, "%s%i weeks ", c, w);
    }
  }

  d = ((seconds % 604800) / 86400);
  if (d != 0) {
    if (1 == d) {
      c = strConcat (c, "%s%i day ", c, d);
    } else {
      c = strConcat (c, "%s%i days ", c, d);
    }
  }

  h = ((seconds % 86400) / 3600);
  if (h != 0) {
    if (1 == h) {
      c = strConcat (c, "%s%i hour ", c, h);
    } else {
      c = strConcat (c, "%s%i hours ", c, h);
    }
  }

  m = ((seconds % 3600) / 60);
  if (m != 0) {
    if (1 == m) {
      c = strConcat (c, "%s%i min ", c, m);
    } else {
      c = strConcat (c, "%s%i mins ", c, m);
    }
  }

  s = (seconds % 60);
  if (s != 0) {
    if (1 == s) {
      c = strConcat (c, "%s%i sec ", c, s);
    } else {
      c = strConcat (c, "%s%i secs ", c, s);
    }
  }

  if (0 == seconds)
    c = strConcat (c, "0 secs ");

  return(c);

}

char *strConcat (char *s, const char *fmt, ...) {
  va_list ap;
  char buf[1024];

  va_start(ap, fmt);
  vsnprintf(buf, sizeof(buf), fmt, ap);
  va_end(ap);

  s = realloc (s, strlen(buf)+1);
  memcpy (s, buf, strlen(buf)+1);

  return(s);

}
