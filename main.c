/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:06:21 by waalexan          #+#    #+#             */
/*   Updated: 2024/05/28 13:54:44 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(const char *s)
{
	int i = 0;
	char *str;

	while(s[i])
		i++;
	str = (char *)malloc(i+1);
	i = 0;
	while(s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] =  '\0';
	return str;

}

char *gnl(int fd)
{
	static int pos;
	static int size;
	static char buffer[BUFFER_SIZE];
	int i = 0;
	static int init;
	char str[7000000];

	if(!init)
	{
		pos = 0;
		size = 0;
		init = 1;
	}
	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	while(1)
	{
		if(pos >= size)
		{
			size = read(fd, buffer, BUFFER_SIZE);
			pos = 0;
				if(size <= 0)
					break;
		}
		str[i++]=buffer[pos++];
		if(str[i - 1] == '\n')
			break;

	}

	str[i] = '\0';
	if(i == 0)
		return NULL;
	return (ft_strdup(str));
}
int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	int i = 1;
		while(i <= 12) 
			printf("[%i] %s",i++, gnl(fd));
	return 0;
}
