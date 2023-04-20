/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:34:30 by somartin          #+#    #+#             */
/*   Updated: 2023/04/20 23:17:33 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h> /*for close*/
# include <stdlib.h> /*for perror, open, link*/
# include <stdio.h> /*for exit, free, malloc*/
# include <errno.h> /*for perror print a system error message*/
# include <fcntl.h> /*for file control options and flags*/
# include <sys/wait.h> /*for pid_t, waitpid*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);

#endif