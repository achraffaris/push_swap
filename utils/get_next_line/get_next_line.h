/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:55:14 by afaris            #+#    #+#             */
/*   Updated: 2022/02/23 12:05:32 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 85

void	free_buffers(char **rest);
int		get_length(char *str, char c);
char	*join_buffers(char **rest, char *buff);
void	save_rest(char **rest, char *buff, int pos);
void	save_rest_st(char **rest, int pos);
char	*get_next_line(int fd);

#endif
