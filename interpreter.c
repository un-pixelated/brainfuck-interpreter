#include <stdio.h>
#include <stdlib.h>

#include "./headers/constants.h"
#include "./headers/input_validation.h"
#include "./headers/memory_management.h"
#include "./headers/pass_one.h"

int main(int argc, char *argv[]) {
        if (validate_number_of_arguments(argc, argv[0]) == 1) return 1;
        
        char *filename = argv[1];

        if (validate_file_extension(filename) == 1) return 1;

        FILE *bf_fileptr = fopen(filename, "r");
        if (validate_file_exists(bf_fileptr, filename) == 1) return 1;

        if (validate_file_not_empty(&bf_fileptr, fgetc(bf_fileptr)) == 1) return 1;

        // bracket_map[position of opening bracket] = position of closing bracket
        // bracket_map[position of closing bracket] = position of opening bracket
        int *bracket_map = malloc(MAP_LEN * sizeof(int));
        if (memory_allocation_check(bracket_map) == 1) {
                fclose(bf_fileptr);
                return 1;
        }

        Stack *validation_stack = stack_init();
        if (memory_allocation_check(validation_stack) == 1) {
                fclose(bf_fileptr);
                return 1;
        }

        // pass 1
        if (build_bracket_map(bracket_map, validation_stack, bf_fileptr) == 1) return 1;
        free_memory(validation_stack, NULL);
        
        char *cell_array = calloc(CELL_ARRAY_LENGTH, CELL_SIZE);
        if (memory_allocation_check(cell_array) == 1) {
                fclose(bf_fileptr);
                return 1;
        }

        // pass 2
        rewind(bf_fileptr);
        
        int cell_ptr = 0;
        int curr_char = 0;
        int char_idx = 0;

        while ((curr_char = fgetc(bf_fileptr)) != EOF) {
                switch (curr_char) {
                        case '>':
                        // wraparound
                        if (cell_ptr == CELL_ARRAY_LENGTH - 1) {
                                cell_ptr = 0;
                                char_idx++;
                                break;
                        }
                        cell_ptr++;
                        char_idx++;
                        break;

                        case '<':
                        // wraparound
                        if (cell_ptr == 0) {
                                cell_ptr = CELL_ARRAY_LENGTH - 1;
                                char_idx++;
                                break;
                        }
                        cell_ptr--;
                        char_idx++;
                        break;

                        case '+':
                        cell_array[cell_ptr]++;
                        // cell wraparound
                        if (cell_array[cell_ptr] == -128) cell_array[cell_ptr] = 0;
                        char_idx++;
                        break;

                        case '-':
                        cell_array[cell_ptr]--;
                        // cell wraparound
                        if (cell_array[cell_ptr] == -1) cell_array[cell_ptr] = 127;
                        char_idx++;
                        break;

                        case '.':
                        printf("%c", cell_array[cell_ptr]);
                        char_idx++;
                        break;

                        case ',':
                        scanf("%c", &cell_array[cell_ptr]);
                        char_idx++;
                        break;
                        
                        case '[':
                        if (cell_array[cell_ptr] == 0) {
                                char_idx = bracket_map[char_idx] + 1;
                                fseek(bf_fileptr, char_idx, SEEK_SET);
                        }
                        else char_idx++;
                        break;

                        case ']':
                        if (cell_array[cell_ptr] != 0) {
                                char_idx = bracket_map[char_idx] + 1;
                                fseek(bf_fileptr, char_idx, SEEK_SET);
                        }
                        else char_idx++;
                        break;

                        default:
                        // handling comments
                        char_idx++;
                        break;
                }
        }
        printf("\n"); 

        free_memory(bracket_map, cell_array, NULL);
        fclose(bf_fileptr);
        return 0;
}