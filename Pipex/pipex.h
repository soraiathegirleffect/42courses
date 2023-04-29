/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 21:52:25 by somartin          #+#    #+#             */
/*   Updated: 2023/04/29 21:52:37 by somartin         ###   ########.fr       */
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

char	*get_next_line(int fd);
void	exec(char *argv, char **envp);
char	*pathfinder(char *cmd, char **envp);
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif