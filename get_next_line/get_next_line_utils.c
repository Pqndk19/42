/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassa-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:12:50 by mmassa-r          #+#    #+#             */
/*   Updated: 2022/11/29 11:13:04 by mmassa-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;

	while (str[i])
	{
		if (str[i] == c)
			return((char *)str + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	i;
	int	j;
	char	*len_s1;
	char	*len_s2;
	char	*new;

	if (!s1 || !s2)
		return (0);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	new[len_s1 + len_s2] = '\0';
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i++] = s2[j++]
	}
	return (new);
}