/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:10:05 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 13:10:06 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <unistd.h> /**	write();	**/
# include <stddef.h> /**	NULL, size_t, offsetof();	**/
# include <stdlib.h> /**	malloc();	**/

# ifndef MY_CONSTANT_H
#  define MY_CONSTANT_H
#  define FALSE 0
#  define TRUE 1
#  define ZERO 0
# endif

void	ft_print_pid(void);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_puterror(const char *error);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif
