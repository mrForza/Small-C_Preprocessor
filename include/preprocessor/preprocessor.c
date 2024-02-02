#include "preprocessor.h"


bool check_comment_existance(FILE* file_pointer) {
    char next_sym = (char)fgetc(file_pointer);
    return (next_sym != EOF && (next_sym == '/' || next_sym == '*') ? true : false);
}


void delete_comments(struct file_handler handler) {
    FILE* write_file_pointer = fopen("formatted.c", "w");
    fseek(handler.file_pointer, 0L, SEEK_SET);
    char prev_sym = (char)fgetc(handler.file_pointer);
    char current_sym = (char)fgetc(handler.file_pointer);
    bool is_a_signleline_comment = false;
    bool is_a_mutliline_comment = false;

    fputc((int)prev_sym, write_file_pointer);
    while (current_sym != EOF) {
        if (is_a_signleline_comment) {
            if (current_sym == '\n') {
                is_a_signleline_comment = false;
                fputc((int)current_sym, write_file_pointer);
            }
        } else if (is_a_mutliline_comment) {
            if (prev_sym == '*' && current_sym == '/') {
                is_a_mutliline_comment = false;
                // fputc((int)'\n', write_file_pointer);
            }
        } else {
            if (prev_sym == '/' && current_sym == '/') {
                is_a_signleline_comment = true;
            } else if (prev_sym == '/' && current_sym == '*') {
                is_a_mutliline_comment = true;
            } else {
                if (current_sym == '/') {
                    bool key = check_comment_existance(handler.file_pointer);
                    fseek(handler.file_pointer, -1, SEEK_CUR);
                    prev_sym = current_sym;
                    current_sym = (char)fgetc(handler.file_pointer);
                    if (key) {
                        continue;
                    } else {
                        fputc((int)prev_sym, write_file_pointer);
                    }
                }
                fputc((int)current_sym, write_file_pointer);
            }
        }
        prev_sym = current_sym;
        current_sym = (char)fgetc(handler.file_pointer);
    }
}