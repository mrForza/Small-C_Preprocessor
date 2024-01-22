#include "stdio.h"


struct file_descriptor {
    const char* name;
    const char* extension;
    unsigned long long size;
};


struct file_handler {
    FILE* file_pointer;
};


const char* get_full_name();