/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:31:39 by kevgusma          #+#    #+#             */
/*   Updated: 2016/02/15 12:12:40 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_memset(void *v, int i, size_t size);
void	ft_bzero(void *v, size_t size);
void	*ft_memcpy(void *v, const void *v1, size_t size);
void	*ft_memccpy(void *v, const void *v1, int i, size_t size);
void	*ft_memmove(void *v, const void *v1, size_t size);
void	*ft_memchr(const void *v, int i, size_t size);
int		ft_memcmp(const void *v, const void *v1, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t size);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t size);
size_t	ft_strlcat(char *s1, const char *s2, size_t size);
char	*ft_strchr(const char *str, int i);
char	*ft_strrchr(const char *str, int i);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t size);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t size);
int		ft_atoi(const char *s1);
int		ft_isalpha(int i);
int		ft_isdigit(int i);
int		ft_isalnum(int i);
int		ft_isascii(int i);
int		ft_isprint(int i);
int		ft_toupper(int i);
int		ft_tolower(int i);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **v);
char	*ft_strnew(size_t size);
void	ft_strdel(char **split);
void	ft_strclr(char *str);
void	ft_striter(char *str, void (*f)(char *str1));
void	ft_striteri(char *str, void (*f)(unsigned int i, char *str));
char	*ft_strmap(char const *str, char (*f)(char c));
char	*ft_strmapi(char const *str, char (*f)(unsigned int i, char c));
int		ft_strequ(char const *str1, char const *str);
int		ft_strnequ(char const *str, char const *str1, size_t size);
char	*ft_strsub(char const *str, unsigned int i, size_t size);
char	*ft_strjoin(char const *str, char const *str2);
char	*ft_strtrim(char const *str);
char	**ft_strsplit(char const *str, char cc);
char	*ft_itoa(int i);
void	ft_putchar(char c);
void	ft_putstr(char const *str);
void	ft_putendl(char const *str);
void	ft_putnbr(int i);
void	ft_putchar_fd(char c, int i);
void	ft_putstr_fd(char const *str, int i);
void	ft_putendl_fd(char const *str, int i);
void	ft_putnbr_fd(int i, int i1);
int		ft_strrint(char const *str, char c);
int		get_next_line(int const fd, char **line);
void	ft_perror(int index);
int		ft_strsrch(char *str, char c);
int		ft_strnbr(char *str);
size_t	ft_strint(const char *str, char c);
void	ft_free(char *str);
void	ft_putnbr_base(size_t nbr, char *base);
size_t	ft_sizetab(char **s);

#endif
