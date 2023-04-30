/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:30:37 by somartin          #+#    #+#             */
/*   Updated: 2023/04/30 13:23:18 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"
/* Child process that run inside a fork, take the filein, put the output in a 
pipe and then exec. fd[0] R, fd[1] for W. Child WRITEs, Parent READSs*/
void	grogu(int *fd, char **av, char **envp)
{
	int		infd;

	close(fd[0]);
	infd = open(av[1], O_RDONLY, 0777);
	if (infd == -1)
	{
		perror("Error in In grogu");
		exit(1);
	}	
	dup2(fd[1], STDOUT_FILENO);
	dup2(infd, STDIN_FILENO);
	exec(av[2], envp);
	close(fd[1]);
}

/* Parent process that take the data from the pipe, change the output for the
 fileout and also close with the exec function, */
void	mando(int *fd, char **av, char **envp)
{
	int		outfd;

	close(fd[1]);
	outfd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfd == -1)
	{
		perror("Error in In mando");
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(outfd, STDOUT_FILENO);
	exec(av[3], envp);
	close(fd[0]);
}
/* envp is an array of pointers to environment variables, 
we use: pipex filein cmd1 cmd2 fileout*/

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	int		pid;

	if (ac != 5)
	{
		return (write(1, "error: need 4 arg\n", 18));
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
	{
		perror("Error in pipe");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error in fork");
		exit(1);
	}
	if (pid == 0)
		grogu(fd, av, envp);
	wait(NULL);
	mando(fd, av, envp);
	return (0);
}
