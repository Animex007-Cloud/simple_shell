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
