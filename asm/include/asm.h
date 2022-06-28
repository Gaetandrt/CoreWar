/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** asm
*/

#ifndef ASM_H_
    #define ASM_H_
    #include "../../include/my.h"
    #define MEM_SIZE (6 * 1024)
    #define IDX_MOD 512   /* modulo of the index < */
    #define MAX_ARGS_NUMBER 4     /* this may not be changed 2^*IND_SIZE */
    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"

    #define REG_NUMBER 16

    typedef char args_type_t;
    #define T_REG 1       /* register */
    #define T_DIR 2       /* direct  (ld  #1,r1  put 1 into r1) */
    #define T_IND 4       /* indirect always relative
( ld 1,r1 put what's in the address (1+pc
into r1 (4 bytes )) */
    #define T_LAB 8       /* LABEL */
    /*
    ** live
    */
    #define CYCLE_TO_DIE 1536    /* number of cycle before beig declared dead */
    #define CYCLE_DELTA 5
    #define NBR_LIVE 40
    /*
    ** size (in bytes)
    */
    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE DIR_SIZE
    /*
    ** op_tab
    */
    /*
    ** header
    */
    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC 0xea83f3 /* why not */

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
} op_t;

    extern op_t op_tab[];
    // COMMENTAIRE DE NATHAN JE SAIS PAS CE QUE C'EST CE PUTAIN DE TRUC

typedef struct header_s {
    int magic;
    int prog_size;
    char *prog_name;
    char *comment;
    FILE *file;
    char **file_contained;
    char *filepath;
} header_t;

typedef struct label_s {
    char *name;
    int index;
    struct label_s *next;
} label_t;

typedef struct instruction_file_s {
    char *instruction;
    char *parametre1;
    char *parametre2;
    char *parametre3;
    struct instruction_file_s *next;
} instruction_file_t;

// ERROR HANDING
void check_file(char *filepath, header_t *header);
void print_error(char *str);
void check_name(header_t *header);
void check_comment(header_t *header);
void deplace_pointer_to_quote(char **line_of_name);
int print_help(void);
void remove_comment(header_t *header);

// PARSE ALL IN STRUCT
char *parse_instruction(char *line_command);
char *parse_p1(char *line_command);
char *parse_p2(char *line_command, char *instruction);
char *parse_p3(char *line_command, char *instruction);
header_t *init_struct(void);
void push_node_at_back(instruction_file_t **my_struct, char **parametres);
instruction_file_t *parse_file(header_t *header);

#endif /* !ASM_H_ */
