#include "test_file_validators.c"
#include "stdio.h"
#include "preprocessor/preprocessor.h"

const char* GREETINGS_TEXT = "The simple Small-C preprocessor\n";

const char* LOGO = "\n"
                   "  ____  ___ ____   ____   __     __   ____                          ____                      _ _           \n"
                   " |  _ \\|_ _/ ___| / ___|  \\ \\   / /  / ___|_ __ ___  ___ ___       / ___|___  _ __ ___  _ __ (_) | ___ _ __ \n"
                   " | |_) || |\\___ \\| |   ____\\ \\ / /  | |   | '__/ _ \\/ __/ __|_____| |   / _ \\| '_ ` _ \\| '_ \\| | |/ _ \\ '__|\n"
                   " |  _ < | | ___) | |__|_____\\ V /   | |___| | | (_) \\__ \\__ \\_____| |__| (_) | | | | | | |_) | | |  __/ |   \n"
                   " |_| \\_\\___|____/ \\____|     \\_/     \\____|_|  \\___/|___/___/      \\____\\___/|_| |_| |_| .__/|_|_|\\___|_|   \n"
                   "                                                                                       |_|                  ";


int main() {
    setvbuf(stdout, NULL, _IOLBF, 0);
    printf("%s", GREETINGS_TEXT);
    printf("%s", LOGO);
    struct file_handler handler;
    FILE* open_file_pointer;
    while (true) {
        char* file_name = get_full_name();
        if (validate_filename(file_name)) {
            char** splitted_info = split_full_name(file_name);
            char* name = splitted_info[0];
            char* extension = splitted_info[1];
            if (validate_extension(extension)) {
                open_file_pointer = fopen(file_name, "r");
                if (validate_file_existance(open_file_pointer)) {
                    handler.file_pointer = open_file_pointer;
                    handler.name = name;
                    handler.extension = extension;
                    fseek(open_file_pointer, 0L, SEEK_END);
                    handler.size = ftell(open_file_pointer);
                    break;
                }
            }
        }
    }
    printf("Name: %s\nExtension: .%s\nSize: %llu bytes\n\n", handler.name, handler.extension, handler.size);
    delete_singleline_comments(handler);
    delete_multiline_comments(handler);
    fclose(handler.file_pointer);
    return 0;
}
