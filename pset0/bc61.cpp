#include <cstdlib>
#include <cstdio>

int main() {

  unsigned long bytes_num{0};

  // This works because every single character can be represented as one byte.
  while(fgetc(stdin) != EOF){
    bytes_num++;
  }

  printf("The total number of bytes is: %8lu\n", bytes_num);
  exit(0);
}
