/*******************************************************
*    print.c        Magic lib           1/17/2026      *
*    Pretty printing for the terminal                  *
*                                                      *
*    (c) 2026 Alex M. (EnderKiwi)                      *
*    Licensed under GNU AFFERO GENERAL PUBLIC LICENSE  *
*******************************************************/
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"

// an idea to put all output into a buffer, so later color
// could be turned off or whatever so it could be put a file more easily
#if 0
#define MAGIC_OUTPUT_COUNT 256
struct magic_output;
struct magic_output {
     struct magic_output *next;
     char data[MAGIC_OUTPUT_COUNT];
     bool special[MAGIC_OUTPUT_COUNT];
};

struct magic_output *new_magic_output(void) {
     struct magic_output *ret = malloc(sizeof(struct magic_output));
     ret->next = NULL;
     for (int i = 0; i < MAGIC_OUTPUT_COUNT; i++) {
          ret->data[i] = 0;
          ret->special[i] = false;
     }
     return ret;
}

struct magic_output *magic_vfmtstr(const char *fmt, va_list va) {
     return NULL;
}
#endif

// TODO: actual formatting code
void vfprint(va_list va, FILE *stream, const char *fmt) {
     while (*fmt) {
          if (*fmt == '{') {
               // formatting
               if (!*(++fmt)) return;
               if (*fmt == '{') {
                    putc('{', stream);
                    fmt++;
                    continue;
               }
               switch (*fmt) {
                    case 'i':
                         int i = va_arg(va, int);
                         fprintf(stream, "%d", i);
                         break;
                    case 's':
                         char *s = va_arg(va, char*);
                         fprintf(stream, "%s", s);
                         break;
                    case 'c':
                         char c = (char)va_arg(va, int);
                         fprintf(stream, "%c", c);
                         break;
                    case 'f':
                         double d = va_arg(va, double);
                         fprintf(stream, "%f", d);
                         break;
                    case 'p':
                         void *p = va_arg(va, void*);
                         fprintf(stream, "%p", p);
                         break;
                    default:
                         return;
               }
               while (*fmt != ' ' && *fmt != '}') {
                    if (!*(++fmt)) return;
               }
               if (*(fmt++) == '}') continue;
          } else if (*fmt == '[') {
               // colors
               if (!*(++fmt)) return;
               if (*fmt == '[') {
                    putc('[', stream);
                    fmt++;
                    continue;
               }
               char *styles[] = MAGIC_COLORS;
               int lastcolor = -1;
               while (*fmt != ']') {
                    if (*fmt == ' ') {
                         if (!*(++fmt)) return;
                         continue;
                    }
                    int color = -1;
                    for (int i = 0; styles[i][0]; i++) {
                         if (styles[i][0] == '.') continue;
                         int j = 0;
                         for (j = 0; styles[i][j]; j++) {
                              if (!*(fmt+j)) return;
                              if (*(fmt+j) != styles[i][j]) break;
                              if (!styles[i][j+1] && *(fmt+j) == styles[i][j]) color = (i/2);
                         }
                         if (color != -1) {
                              fmt += j;
                              if (lastcolor != -1) {
                                   if (color == 108 && ((lastcolor >= 30 && lastcolor <= 39) || (lastcolor >= 90 && lastcolor <= 99))) lastcolor += 10;
                                   if (lastcolor != 108) fprintf(stream, "\x1b[%dm", lastcolor);
                              }
                              lastcolor = color;
                              //printf("\x1b[%dm", color);
                              //printf("%d\n", color);
                              break;
                         }
                    }
                    if (*fmt == ']') break;
                    if (!*(++fmt)) return;
               }
               if (lastcolor != 108) fprintf(stream, "\x1b[%dm", lastcolor);
               fmt++;
               
          } else {
               putc(*fmt, stream);
               fmt++;
          }
     }
}

void vprint(va_list va, const char *fmt) {
     vfprint(va, stdout, fmt);
}

void fprint(FILE *stream, const char *fmt, ...) {
     va_list va;
     va_start(va, fmt);
     vfprint(va, stream, fmt);
     va_end(va);
}

/**  Pretty printing function
*   Use {TYPE (FORMAT)} for formatted printing (FORMAT optional)
*   Use [STYLE] for styled printing
*/
void print(const char *fmt, ...) {
     va_list va;
     va_start(va, fmt);
     vprint(va, fmt);
     va_end(va);
}
