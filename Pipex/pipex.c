/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:30:37 by somartin          #+#    #+#             */
/*   Updated: 2023/04/15 00:25:06 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	grogu(int fd[2], char *infile, char *cmd, char **envp);

void	mando(int fd[2], char *outfile, char *cmd, char **envp);

int main(int ac, char **av, char **envp )
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
	waitpid(pid, NULL, 0);
	mando(fd, av[4], av[3], envp);
	return(0);
}