/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:28:41 by mcesar-d          #+#    #+#             */
/*   Updated: 2023/04/28 18:04:24 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1024 // adicionei o buffer_size da get_next_line

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t size);
void	*ft_memchr(const void *s, int c, size_t size);
void	*ft_memset(void *s, int c, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strnstr(const char *s1, const char *s2, size_t size);
int		ft_atoi(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		ft_findrchr(const char *s, int c);
void	ft_putstrs(char *before, char *str, char *after, int fd);

/* ---------------------------------------------------------------------*\
|	get_next_line_bonus													|
\* ---------------------------------------------------------------------*/
char	*get_next_line(int fd);
char	*cut_act(char *actual);
char	*line_to_send(char *actual);
char	*ft_strjoin_alt(char *s1, char *s2);
int		check_break(char *actual);

/* ---------------------------------------------------------------------*\
|	extra funtions														|
\* ---------------------------------------------------------------------*/
char	**ft_str_arrayndup_free(size_t start, char **array);
size_t	ft_str_arraylen(char **array);
int		ft_strcmp_eq(char *s1, char *s2);
void	ft_matrix_free(char **ptr);
int		skip(const char *s, int i, char c);
char	**ft_split2(char const *s, char c);
int		ft_strcmp_char(char *s1, char c);

#endif
