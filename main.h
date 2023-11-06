#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>

#define READ_BUFF_SIZE 1024
#define WRITE_BUFF_SIZE 1024
#define BUFF_FLUSH -1

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define HISTORY_FILE	".shell_history"
#define HISTORY_MAX	4096

#define LOWERCASE	1
#define CON_UNSIGNED	2

#define GETLINE		0
#define STRTOK		0

extern char **environ;

/**
 * struct list_s - Linked list
 * @i: integer
 * @str: string
 * @next: points to next node.
 */
typedef struct list_s
{
	int i;
	char *str;
	struct list_s *next;
} list_t;

/**
 * struct infos - Linked list
 * @args: strings that holds arguments.
 * @argv: argument vector.
 * @path: string path for present command.
 * @argc: argument count
 * @env: env
 * @environ: custom made copy of env.
 * @err_count: counts error occurrences.
 * @err_num: returns exit number.
 * @linecount_flag: line of input.
 * @file_name: program file name.
 * @moniker: the node alias.
 * @env_changed: switch mode if environment changed.
 * @history: the history node.
 * @stats: the return status value of executed command.
 * @cmd_buff: address of pointer to the cmd buffer.
 * @cmd_buff_type: command type and operators.
 * @read_fd: read line input.
 * @history_count: line of number from history.
 */
typedef struct infos
{
	char *args;
	char **argv;
	char *path;
	int argc;
	list_t *env;
	char **environ;
	unsigned int err_count;
	int err_num;
	int linecount_flag;
	char *file_name;
	list_t *moniker;
	int env_changed;
	list_t *history;
	int stats;
	char **cmd_buff;
	int cmd_buff_type;
	int read_fd;
	int history_count;
} infos_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtins - builtin functions
 * @flag: the builtin flag
 * @func: the function of the builtin
 */
typedef struct builtins
{
	char *flag;
	int (*func)(infos_t *);
} builtins_t;

void _puts(char *);
int _errputchar(char);
int _putchar(char);
void clear_infos(infos_t *);
void free_infos(infos_t *, int);
void set_infos(infos_t *, char **);
void sfree(char **);
int buffree(void **);
void free_list(list_t **);
char **token(char *, char *);
char **token2(char *, char);
int de_lim(char, char *);
int rmoniker(infos_t *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
int rvars(infos_t *);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
int _strcmp(char *, char *);
int rstr(char **, char *);
int is_chain(infos_t *, char *, size_t *);
void if_chain(infos_t *, char *, size_t *, size_t, size_t);
int shell_exit(infos_t *);

#endif
