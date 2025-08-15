/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:01:22 by lroberts          #+#    #+#             */
/*   Updated: 2025/08/10 11:43:13 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Removes a file descriptor node from the list
 *
 * @param fd_list The pointer to the head of the file descriptor list
 * @param fd The file descriptor to remove
 */
void	remove_fd(t_fd_list **fd_list, int fd)
{
	t_fd_list	*current;
	t_fd_list	*prev;

	current = *fd_list;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (prev)
				prev->next = current->next;
			else
				*fd_list = current->next;
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

/**
 * @brief Joins two strings into a newly allocated string.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return A pointer to the newly allocated concatenated string, or NULL.
 */
// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!s1)
// 		s1 = "";
// 	if (!s2)
// 		s2 = "";
// 	i = 0;
// 	j = 0;
// 	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	while (s1[i] != '\0')
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j] != '\0')
// 	{
// 		str[i + j] = s2[j];
// 		j++;
// 	}
// 	str[i + j] = '\0';
// 	return (str);
// }

/**
 * @brief Finds the first occurrence of a character in a string.
 *
 * @param s The string to search.
 * @param i The character to find.
 * @return A pointer to the first occurrence of the character, or NULL.
 */
char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}

/**
 * @brief Extracts a substring from a string.
 *
 * @param s The source string.
 * @param start The starting index of the substring.
 * @param len The maximum length of the substring.
 * @return A pointer to the newly allocated substring, or NULL.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s || s[0] == '\0')
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		return (str[0] = '\0', str);
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
