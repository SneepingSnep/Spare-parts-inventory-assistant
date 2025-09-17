#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define SPAREPARTSIZE 3
#define Queriessyze 2
bool RUNNING = 1;

bool succes = 0;
char parts[SPAREPARTSIZE][20] = {"hydraulic pump", "PLC module", "servo motor"};
char inputbuffer[36];
char queries[Queriessyze][36] = {"What parts do you got?",
                                 "Is there anything in stock at all?"};

int main() {

  printf("Hej. Welcome to the spare parts inventory!\n\nWhich part do you "
         "need?\n");

  while (RUNNING) {
    fgets(inputbuffer, sizeof(inputbuffer), stdin);
    int stringcount = strlen(inputbuffer);
    inputbuffer[stringcount - 1] = '\0';

    for (size_t i = 0; i < _countof(parts); i++) {
      if (strcmp(inputbuffer, parts[i]) == 0) {
        printf("I have got %s here for you :). Bye!\n", parts[i]);
        succes = 1;
      }
    }

    if (succes) {
      return EXIT_SUCCESS;
    } else {
      for (size_t i = 0; i < _countof(queries); i++) {
        if (strcmp(inputbuffer, queries[i]) == 0) {
          if (i == 0) {
            printf("We have\n");
            for (int j = 0; j < _countof(parts); j++) {
              printf("%d: %s\n", j + 1, parts[j]);
            }
            succes = 1;
          } else if (i == 1) {
            printf("We have: ");
            int count = 0;
            for (int j = 0; j < _countof(parts); j++) {
              count++;
            }
            printf("%d part(s) in stock... Ask for <What parts do you got?> "
                   "for parts list:\t",
                   count);
            succes = 1;
          }
        }
      }
    }
    succes
        ?: printf("I am afraid we don't have any %s in the inventory :(\n Try "
                  "entering <What parts do you got?> to see the parts list!\n",
                  inputbuffer);
    // if (!succes) {
    //   printf("I am afraid we don't have any %s in the inventory :(\n Try "
    //          "entering <What parts do you got?> to see the parts list!\n",
    //          inputbuffer);
    // }
    memset(inputbuffer, 0, sizeof(inputbuffer));
    succes = 0;
  }
}