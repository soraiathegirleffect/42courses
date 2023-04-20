/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:30:37 by somartin          #+#    #+#             */
/*   Updated: 2023/04/20 23:54:48 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*pathfinder(char *cmd, char **envp)
{
	char	**arrayofpaths;
	char	*thepath;
	char	*tmp;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	arrayofpaths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (arrayofpaths[i])
	{
		tmp = ft_strjoin(arrayofpaths[i], "/");
		thepath = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(thepath, F_OK | X_OK) == 0)
			return (thepath);
		i++;
	}
	return (0);
}

void	grogu(int *fd, char **av, char **envp)
{
	int		infd;
	int		execstat;
	char	*path;

	close(fd[0]);
	infd = open(av[1], O_RDONLY);
	if (infd == -1)
		perror("Error in In grogu");
	dup2(infd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	path = pathfinder(av[2], envp);
	execstat = execve(path, ft_split(av[2], ' '), envp);
	if (execstat == -1)
		perror("Error in execv");
	close(fd[1]);
}

void	mando(int *fd, char **av, char **envp)
{
	int		outfd;
	int		execstat;
	char	*path;

	close(fd[1]);
	outfd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfd == -1)
		perror("Error in Out mando");
	dup2(outfd, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	path = pathfinder(av[3], envp);
	execstat = execve(path, ft_split(av[3], ' '), envp);
	if (execstat == -1)
		perror("Error in execv");
	close(fd[0]);
}

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	pid;

	if (ac != 5)
		return (write(1, "error: need 4 arg\n", 18));
	if (pipe(fd) == -1)
	{
		perror("Error in pipe");
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error in fork");
		return (1);
	}
	if (pid == 0)
		grogu(fd, av, envp);
	wait(NULL);
	mando(fd, av, envp);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
