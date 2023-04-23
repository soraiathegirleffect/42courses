/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:18:37 by somartin          #+#    #+#             */
/*   Updated: 2023/04/23 23:59:57 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = pathfinder(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{
		perror("error in execve");
		exit(1);
	}
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
		if (access(thepath, F_OK) == 0)
			return (thepath);
		i++;
	}
	free(thepath);
	free(arrayofpaths);
	return (0);
}
