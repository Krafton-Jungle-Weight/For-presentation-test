#include <stdio.h>

int main(void) {
  int a = 0;
  if (a = 5) { // clang-tidy: warning (assign instead of compare)
    printf("a is 5\\n");
  }
  return 0;
}