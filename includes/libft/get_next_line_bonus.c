/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:57:02 by lroberts          #+#    #+#             */
/*   Updated: 2025/08/01 19:26:05 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Takes data until \n from file and appends it to end of buffer
 * -- Returns until a \n from the front (eg a line of text)
 *
 * @param fd The file descriptor that you want to read line-to-line from
 * @return A dynamically allocated string with a '\0' behind
 * the '\n' (allow for eg printf() usage)
 * @remarks You need to free the return in the caller function
 */
char	*get_next_line(int fd)
{
	static t_fd_list	*fd_list;
	char				*line;
	char				**backup;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = get_backup(&fd_list, fd);
	if (!backup)
		return (NULL);
	*backup = append_backup(*backup, fd);
	if (*backup == NULL)
		return (remove_fd(&fd_list, fd), NULL);
	line = cut_line(*backup);
	if (line == NULL)
		return (free(*backup), remove_fd(&fd_list, fd), NULL);
	*backup = ft_shave_backup(*backup);
	return (line);
}

/**
 * @brief Gets or creates a backup pointer for the specific file descriptor
 *
 * @param fd_list The pointer to the head of the file descriptor list
 * @param fd The file descriptor to find or create a backup for
 * @return A pointer to the backup string pointer, or NULL if an error occurs
 */
char	**get_backup(t_fd_list **fd_list, int fd)
{
	t_fd_list	*current;
	t_fd_list	*new_node;

	current = *fd_list;
	while (current)
	{
		if (current->fd == fd)
			return (&current->backup);
		current = current->next;
	}
	new_node = (t_fd_list *)malloc(sizeof(t_fd_list));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->backup = NULL;
	new_node->next = *fd_list;
	*fd_list = new_node;
	return (&new_node->backup);
}

/**
 * @brief Reads from a fd and appends the content to the backup str.
 *
 * @param backup The current backup string.
 * @param fd The file descriptor to read from.
 * @return A pointer to the updated backup string, or NULL if an error occurs.
 */
char	*append_backup(char *backup, int fd)
{
	char	*buffer;
	char	*temp;
	int		red;

	red = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	red = read(fd, buffer, BUFFER_SIZE);
	while (red > 0)
	{
		buffer[red] = '\0';
		temp = ft_strjoin(backup, buffer);
		free(backup);
		if (!temp)
			return (free(buffer), NULL);
		backup = temp;
		if (ft_strchr(backup, '\n'))
			break ;
		red = read(fd, buffer, BUFFER_SIZE);
	}
	if (red == -1)
		return (free(backup), free(buffer), NULL);
	free(buffer);
	return (backup);
}

/**
 * @brief Extracts line (up to and incl the first nl) from the backup str.
 *
 * @param backup The backup string.
 * @return A pointer to the newly allocated line, or NULL if allocation fails.
 */
char	*cut_line(char *backup)
{
	char	*line;
	int		i;
	int		include_nl;

	if (!backup || backup[0] == '\0')
		return (NULL);
	i = 0;
	while (backup[i] != '\0' && backup[i] != '\n')
		i++;
	include_nl = 0;
	if (backup[i] == '\n')
		include_nl = 1;
	line = ft_substr(backup, 0, i + include_nl);
	return (line);
}

/**
 * @brief Removes extracted line from backup str, leaves remaining content.
 *
 * @param backup_unshaven The original backup string.
 * @return A pointer to the updated backup string, or NULL if no content remains.
 */
char	*ft_shave_backup(char *backup_unshaven)
{
	int		i;
	char	*backup_shaven;

	if (!backup_unshaven)
		return (NULL);
	i = 0;
	while (backup_unshaven[i] && backup_unshaven[i] != '\n')
		i++;
	if (backup_unshaven[i] == '\0')
	{
		free(backup_unshaven);
		return (NULL);
	}
	backup_shaven = ft_substr(backup_unshaven, i + 1,
			ft_strlen(backup_unshaven) - i - 1);
	free(backup_unshaven);
	return (backup_shaven);
}
