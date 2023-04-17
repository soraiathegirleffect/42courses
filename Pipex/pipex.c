/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:30:37 by somartin          #+#    #+#             */
/*   Updated: 2023/04/18 00:12:19 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char pathfinder(char *cmd, char **envp)
{
	char **mypaths;
	char **mycmdargs;
	char *cmd;

	while (*envp && !ft_strnstr(*envp, "PATH=", 5))
		envp++;
	PATH_from_envp = ft_substr(*envp, 5, ft_strlen(*envp) - 5);
	mypaths = ft_split(PATH_from_envp, ":");
	mycmdargs = ft_split(cmd, " ");
	
}

void	grogu(int fd[2], char *infile, char *cmd, char **envp)
{
	close(fd[0]); /*close the end of the pipe we don't use*/
	int fd = open(infile, O_RDONLY);
		if (fd == -1)
			perror("Error in In grogu");
	dup2(fd, STDIN_FILENO); /*infile to be stdin, input, fd to be execve() input*/
	dup2(fd[1], STDOUT_FILENO); /*end[1] to be stdout, to write to end[1] the output, we want fd[1] to be execve() stdout*/
	pathfinder(cmd, envp);
	close(fd[1]);
	
}
void	mando(int fd[2], char *outfile, char *cmd, char **envp)
{
	close(fd[1]);
	int fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
			perror("Error in Out mando");
	dup2(fd, STDOUT_FILENO);/*f2 is the stdout*/
	dup2(fd[0], STDIN_FILENO);/*end[0] is the stdin*/
	pathfinder(cmd, envp);
	close(fd[0]); /*we can now after this execute the command with execve()*/
}
int main(int ac, char **av, char **envp) /*envp is an array of pointers to environment variables*/
{
	int fd[2];
	
	if (ac != 5) /*pipex filein cmd1 cmd2 fileout*/
		return (write(1, "error: need 4 arg\n", 18));

	if (pipe(fd) == -1)
	{
		perror("Error in pipe"); /*we use perror bc will work even after switch term to outfile bc it prints to stderr.*/
		return 1;
	}
	int pid = fork();
	if (pid == -1)
	{
		perror("Error in fork");
		return 1;
	}
	if (pid == 0) /*child*/
		grogu(fd, av[1], av[2], envp);
	wait(NULL);
	mando(fd, av[4], av[3], envp);
	close(fd[0]); /*because main has these open due to pipe preventing from finishing execution*/
	close(fd[1]);
	return(0);
}