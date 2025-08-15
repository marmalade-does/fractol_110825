/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:01:50 by lroberts          #+#    #+#             */
/*   Updated: 2025/08/09 14:54:06 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
	//////////////////////
			types
	//////////////////////	*/

typedef struct s_list // libft
{
	void			*content;
	struct s_list	*next;
}		t_list;

typedef struct s_fd_list // gnl
{
	int					fd;
	char				*backup;
	struct s_fd_list	*next;
}		t_fd_list;

/* 	//////////////////////
		get_next_line
	//////////////////////	*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// typedef struct s_fd_list
// {
// 	int					fd;
// 	char				*backup;
// 	struct s_fd_list	*next;
// }	t_fd_list;

char	*get_next_line(int fd);
char	*ft_shave_backup(char *backup_unshaven);
char	*cut_line(char *backup);
char	*append_backup(char *backup, int fd);
char	**get_backup(t_fd_list **fd_list, int fd);

char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int i);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	remove_fd(t_fd_list **fd_list, int fd);

/*	//////////////////
		ft_printf()
	//////////////////	*/
// ft_printf.c
int		ft_printf(const char *str, ...);
int		h_pct(const char *str, int *idx, va_list *args, int *len);
int		h_chr(const char *str, int *idx, int *len);

// print_types.c
int		put_charsum(const char c, int *len);
int		str(const char *str, int *len);
int		number(int nb, int *len);
int		unsigned_int(unsigned int u, int *len);

// print_hexptry.c
int		rec_ptr(size_t ptr, int *len);
int		print_ptr(size_t ptr, int *len);
int		hexadecimal_up(unsigned int x, int *len);
int		hexadecimal_low(unsigned int x, int *len);

/* 	//////////////////////
			libft
	//////////////////////	*/

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isascii(int i);
int		ft_isdigit(int i);
int		ft_isprint(int i);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int i);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int i);
int		ft_toupper(int i);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *str, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
