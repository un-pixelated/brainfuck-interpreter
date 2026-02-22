#include <stdio.h>
#include <stdlib.h>

#include "./headers/constants.h"
#include "./headers/helpers.h"
#include "./headers/stack.h"

int main(int argc, char *argv[]) {
        if (argc < 2) {
                fprintf(stderr, "usage: %s file.bf\n", argv[0]);
                return 1;
        }

        if (!validate_ext(argv[1])) {
                fprintf(stderr, "%s is not a valid brainfuck file\nfile extension must be .bf\n", argv[1]);
                return 1;
        }

        FILE *bf_fileptr = fopen(argv[1], "r");
        if (bf_fileptr == NULL) {
                perror(argv[1]);
                return 1;
        }

        char *cell_array = calloc(ARRAY_LENGTH, CELL_SIZE);
        if (cell_array == NULL) {
                fprintf(stderr, "couldn't allocate memory\n");
                return 1;
        }

        int curr_char;
        int char_num = 0;
        int bracket_map[ARRAY_LENGTH];
        while ((curr_char = fgetc(bf_fileptr)) != EOF) {
                if (curr_char != '[' && curr_char != ']') {}

                
        }

        fclose(bf_fileptr);
        return 0;
}