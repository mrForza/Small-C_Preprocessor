#include "test_file_validators.c"
#include "file_handler/file_handler.h"
#include "stdio.h"

const char* GREETINGS_TEXT = "The simple Small-C preprocessor\n";

const char* LOGO = "\n"
                   "  ____  ___ ____   ____   __     __   ____                          ____                      _ _           \n"
                   " |  _ \\|_ _/ ___| / ___|  \\ \\   / /  / ___|_ __ ___  ___ ___       / ___|___  _ __ ___  _ __ (_) | ___ _ __ \n"
                   " | |_) || |\\___ \\| |   ____\\ \\ / /  | |   | '__/ _ \\/ __/ __|_____| |   / _ \\| '_ ` _ \\| '_ \\| | |/ _ \\ '__|\n"
                   " |  _ < | | ___) | |__|_____\\ V /   | |___| | | (_) \\__ \\__ \\_____| |__| (_) | | | | | | |_) | | |  __/ |   \n"
                   " |_| \\_\\___|____/ \\____|     \\_/     \\____|_|  \\___/|___/___/      \\____\\___/|_| |_| |_| .__/|_|_|\\___|_|   \n"
                   "                                                                                       |_|                  ";


int main() {
    printf("%s", GREETINGS_TEXT);
    printf("%s", LOGO);
    struct file_handler handler;
    FILE* file_pointer;
    while (true) {
        char* file_name = get_full_name();
        if (validate_filename(file_name)) {
            char** splitted_info = split_full_name(file_name);
            char* name = splitted_info[0];
            char* extension = splitted_info[1];
            if (validate_extension(extension)) {
                file_pointer = fopen(file_name, "r");
                if (validate_file_existance(file_pointer)) {
                    handler.file_pointer = file_pointer;
                    handler.name = name;
                    handler.extension = extension;
                    fseek(file_pointer, 0L, SEEK_END);
                    handler.size = ftell(file_pointer);
                    break;
                }
            }
        }
    }
    printf("Name: %s\nExtension: .%s\nSize: %llu bytes", handler.name, handler.extension, handler.size);
    return 0;
}
