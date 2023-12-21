/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:46 by kburalek          #+#    #+#             */
/*   Updated: 2023/02/22 13:03:52 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *str, size_t num);
char	*ft_strchr(const char *str, int val);
int		ft_strncmp(const char *str1, const char *str2, size_t num);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char const *s, char val);
int		get_next_line(int fd, char **line);
int		ft_new_line(char *buf);

#endif
