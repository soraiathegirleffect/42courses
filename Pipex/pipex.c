/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:30:37 by somartin          #+#    #+#             */
/*   Updated: 2023/04/15 01:28:15 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	grogu(int fd[2], char *infile, char *cmd, char **envp)
{
	close(fd[0]);
	int fd = open(infile, O_RDONLY);
		if (fd == -1)
			perror("Error in Infile");
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
}
void	mando(int fd[2], char *outfile, char *cmd, char **envp)
{
	close(fd[1]);
	int fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
			perror("Error in outfile");
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}
int main(int ac, char **av, char **envp)
{
	int fd[2];
	
	if (ac != 5) /*pipex filein cmd1 cmd2 fileout*/
		return (write(1, "error: need 4 arg\n", 18));

	if (pipe(fd) == -1)
	{
		perror("Error in pipe");
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
	close(fd[0]); /*because main has these open on main due to pipe preventing from finishing execution*/
	close(fd[1]);
	return(0);
}