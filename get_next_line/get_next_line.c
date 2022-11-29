/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassa-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:07:11 by mmassa-r          #+#    #+#             */
/*   Updated: 2022/11/25 12:07:13 by mmassa-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* PASSAR CHAR PARA SAVE
1. procurar funcao pro \n
2. alocar memoria pa o buffer
3. se nao encontrar \n, e read_bytes n forem 0
	fazer read() se read() for negativo libertar memoria buffer
4.juntar save com o buffer
5. libertar buffer
6. return save
*/
char	*ft_read_and_save(int fd, char save)
{
	char	*buff;
	int		read_bytes;
	char	backslash_n;

	backslash_n = ft_strchr(save, '\n');
	if (backslash_n)
		return (save);
	read_bytes = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!backslash_n && read_bytes > 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (0);
		}
		buffer[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buffer);
	return (save);
}
/* PASSAR DO SAVE PA LINE
1. se save n existir ret. null
2. saber o tamanho da string ate \n(excl.)
3. alocar mem para line
4. passar tudo do save pa line
5. se o ultimo char do save for \n por no line tmb
6. return line
*/
char	*ft_get_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if(!save[i])
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i] == '\n';
	return (line);
}
/*Qnd o buffer e maior q a propria linha o save fica com mais char
depois do \n, esta funcao fica c esses char para o prox while da main
1. calcular o tamnho do save
2. negar o save e libertar mem do save
3. alocar mem para str c o tamanho do save menos o tamanho de save (ultima linha)
4. passar conteudo de save para str
5. libertar mem de save
6, return str
*/
char	*ft_save(save)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	str = malloc((ft_strlen(save) - i + 1) * sizeof(char));
	i++;
	j = 0;
	while (j <= i)
	{
		str[j] = save[i];
		j++;
		i++;
	}
	free(save);
	return(str);
}

char	*get_next_line(int	fd)
{
	char	*line;
	static char 	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_and_save(fd, save);
	if(!save)
		return (0);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("files/miranha.txt", O_RDONLY);
	//fd = open("files/simpsons.txt", O_RDONLY); 
	//fd = open("files/hp.txt", O_RDONLY);
 	//fd = open("files/hltv.txt", O_RDONLY);
	//fd = open("files/big_line_with_nl", O_RDONLY);
	//fd = open("files/big_line_no_nl", O_RDONLY); 
	i = 1;
	while ((line = get_next_line(fd)))
	{
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
