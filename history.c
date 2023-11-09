#include "main.h"

/**
 * read_history - Entry point
 * @info: contains argument.
 *
 * Description: reads history from file
 * Return: history_count on Success, 0 if failed.
 */
int read_history(infos_t *info)
{
	int a, recent = 0, linecount_flag = 0;
	ssize_t fd, read_len, fsize = 0;
	struct stat st;
	char *buff = NULL, *fname = get_history_file(info);

	if (!fname)
		return (0);

	fd = open(fname, O_RDONLY);
	free(fname);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buff = malloc(sizeof(char) * (fsize + 1));
	if (!buff)
		return (0);
	read_len = read(fd, buff, fsize);
	buff[fsize] = 0;
	if (read_len <= 0)
		return (free(buff), 0);
	close(fd);

	for (a = 0; a < fsize; ++a)
		if (buff[a] == '\n')
		{
			buff[a] = 0;
			build_history_list(info, buff + recent, ++linecount_flag);
			recent = a + 1;
		}
	if (recent != a)
		build_history_list(info, buff + recent, ++linecount_flag);
	free(buff);
	info->history_count = linecount_flag;
	while (info->history_count-- >= HISTORY_MAX)
		remove_node(&(info->history), 0);
	reindex_history(info);
	return (info->history_count);
}

/**
 * reindex_history - Entry point
 * @info: parameter that contains argument.
 *
 * Description: index the history.
 * Return: the new history index
 */
int reindex_history(infos_t *info)
{
	list_t *node = info->history;
	int a = 0;

	while (node)
	{
		node->i = ++a;
		node = node->next;
	}
	return (info->history_count = a);
}

/**
 * build_history_list - Entry point
 * @info: parameter that contains argument.
 * @buff: buffer
 * @linecount_flag: the history line count from history_count.
 *
 * Description: adds entry to history.
 * Return: Always 0 (On Success)
 */
int build_history_list(infos_t *info, char *buff, int linecount_flag)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	plus_node_last(&node, buff, linecount_flag);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * get_history_file - Entry point
 * @info: parameter that contains argument.
 *
 * Description: fetch the history file from source.
 * Return: string from allocated history file.
 */
char *get_history_file(infos_t *info)
{
	char *bf/*buffer*/, *inv;

	inv = get_env(info, "HOME=");
	if (!inv)
		return (NULL);
	bf = malloc(sizeof(char) * (_strlen(inv) + _strlen(HISTORY_FILE) + 2));
	if (!bf)
		return (NULL);
	bf[0] = 0;
	_strcpy(bf, inv);
	_strcat(bf, "/");
	_strcat(bf, HISTORY_FILE);
	return (bf);
}
