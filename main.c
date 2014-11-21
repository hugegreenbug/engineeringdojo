#include <stdio.h>
#include <stdlib.h>
#include "libmym.h"

int main(int argc, char **argv) {
  double res;
  double input;
  char *end;

  if (argc < 2) {
    printf("Usage: ./main num\n");
    exit(1);
  }

  input = strtod(argv[1], &end);
  if (!input && !end) {
    printf("Invalid number given\n");
    exit(1);
  }

  res = newtan(input);
  printf("Tan: %f\n", res);
}
