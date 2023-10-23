#ifndef CALC_ASSEMBLER_H
#define CALC_ASSEMBLER_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>

#include "../GlobalHeaders/config.h"
#include "../Processor/Stack/src/recalloc/recalloc.h"
#include "../FileWork/TextReadFile.h"

struct Lashes
{
    char LABEL_NAME[100];
    size_t label_ip;
};

struct UndefLashes
{
    char UNDEF_LABEL_NAME[100];
    size_t UNDEF_BUFFER_POS;
};

/*Max asm fubc name size*/
static const size_t MAX_FUNC_NAME_SIZE = 30;

/*Max argument size (double can take up a lot of space)*/
static const size_t MAX_ARGUMENT_SIZE = 300;

/*Start buffer size, if the size is not enough,
it is multiplied by a constant : Buffer multiplier*/
static const size_t START_BUFFER_SIZE = 1000;

/*Buffer multiplier*/
static const size_t BUFFER_MULTIPLIER = 2;

/*Buffer for reading the function name*/
/*INACCURACY of buffer size for mult*/
static const size_t INACCURACY = 4;

/*MAX LABEL SIZE*/
static const size_t MAX_LABEL_NUMBER = 1000;

/*the extra byte for the last character*/
static const size_t EXTRA_BYTE = 1;

void assembler(const char* FILE_NAME_INPUT, const char* FILE_NAME_OUTPUT);

void toupper_all(char *str);

void argument_determinant(  
                            char*           pointer_to_write    , 
                            size_t*         offset              , 
                            int64_t         bytecode            , 
                            char*           argument            , 
                            int             argument_size       , 
                            UndefLashes*    undeflabels         , 
                            size_t*         undeflabelspos      , 
                            size_t*         ip
                        );

int sscanf_s_fidex_n(
                        const char*     input       , 
                        char*           output      , 
                        size_t*         input_offset, 
                        size_t*         output_size
                    );

#endif // !CALC_ASSEMBLER_H