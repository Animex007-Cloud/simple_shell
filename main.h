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
 * @alias: the node alias.
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
	list_t *alias;
	int env_changed;
	list_t *history;
	int stats;
	char **cmd_buff;
	int cmd_buff_type;
	int read_fd;
	int history_count;
} infos_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, NULL, NULL, 0, 0, 0, NULL, NULL, 0, NULL, 0, NULL, \
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
int ralias(infos_t *);
char *_strdup(const char *);
void _puts(char *);
int rvars(infos_t *);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
int _strcmp(char *, char *);
int rstr(char **, char *);
int is_chain(infos_t *, char *, size_t *);
void if_chain(infos_t *, char *, size_t *, size_t, size_t);
int shell_exit(infos_t *);
int interactive(infos_t *);
int _isalpha(int);
int _atoi(char *);
void print_err(infos_t *, char *);
int print_dec(int, int);
int err_atoi(char *);
char *converter(long int, int, int);
int _strlen(char *);
char *_strcat(char *, char *);
char *init(const char *, const char *);
char *_memset(char *, char, unsigned int);
void *_realloc(void *, unsigned int, unsigned int);
list_t *plus_node(list_t **, const char *, int);
list_t *plus_node_last(list_t **, const char *, int);
int remove_node(list_t **, unsigned int);
size_t print_list_str(const list_t *);
list_t *node_init(list_t *, char *, char);
int env_list(infos_t *);
int reindex_history(infos_t *);
int build_history_list(infos_t *, char *, int);
char *get_history_file(infos_t *);
char *get_env(infos_t *, const char *);
char *_strcpy(char *, char *);
int read_history(infos_t *);
int hsh(infos_t *, char **);
int write_history(infos_t *);
int _fdput(char c, int fd);
int _fdputs(char *str, int fd);
int my_cd(infos_t *);
int shell_help(infos_t *);
size_t print_list(const list_t *);
int my_history(infos_t *);
int unset_alias(infos_t *, char *);
int set_alias(infos_t *, char *);
int print_alias(list_t *);
int my_alias(infos_t *);
void fork_cmd(infos_t *);
int s_builtins(infos_t *);
void s_cmd(infos_t *);
int my_env(infos_t *);
int my_unsetenv(infos_t *);
int my_setenv(infos_t *);
char **get_environ(infos_t *);
int unset_env(infos_t *, char *);
int set_env(infos_t *, char *, char *);
ssize_t get_node(list_t *, list_t *);
char **list_str(list_t *);
size_t list_len(const list_t *);
char *chars_x(char *, int, int);
int _iscmd(infos_t *, char *);
char *f_path(infos_t *, char *, char *);

#endif
