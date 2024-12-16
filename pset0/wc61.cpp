#include <cstdlib>
#include <cstdio>
#include <cctype>

int main() {

  unsigned long bytes_num{0};
  unsigned long word_count{0};
  unsigned long line_count{0};

  // Initialize the previous character as a space
  int previous_character{0x20U};
  int character{fgetc(stdin)};

  while(character != EOF){
    bytes_num++;

    // If the current character is not space but the previous one is
    // Then a new word has started.
    // Because previous_character was initialized to space ths will
    // work even for a stdin with a single no space character.
    if (!isspace(character) && isspace(previous_character)){
        word_count++;
    }
    // 10 is the value of the newline character \n.
    if (character == 0x0aU){
      line_count++;
    }
    previous_character = character;
    character = fgetc(stdin);
  }

  printf("The total number of lines is: %8lu\n", line_count);
  printf("The total number of words is: %8lu\n", word_count);
  printf("The total number of bytes is: %8lu\n", bytes_num);
  exit(0);
}
