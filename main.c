#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

#include "colors.h"


int main() {
     double a = 0.;
     double b = 0.;
     print("[green]Please input a number[- gray]: [-]");
     scanf("%lf", &a);
     print("[green]Please input a number[- gray]: [-]");
     scanf("%lf", &b);
     print("[purple]{f}[gray]*[purple]{f}[yellow]=[blue]{f}[-]\n", a, b, a*b);
     return 0;
}
