#include <stdio.h>
#include "constants.h"

int main(int argc, char *argv[]) {
        if (argc < 2) {
                fprintf(stderr, "usage: %s file.bf\n", argv[0]);
                return 1;
        }

        // TODO: Add .bf validation

        FILE *bf_fileptr = fopen(argv[1], "r");
        if (bf_fileptr == NULL) {
                perror(argv[1]);
                return 1;
        }

        int cell_array[ARRAY_LENGTH];

        int curr_char;
        while ((curr_char = fgetc(bf_fileptr)) != EOF) {

        }

        fclose(bf_fileptr);
        return 0;
}