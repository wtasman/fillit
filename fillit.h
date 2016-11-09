/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:00:07 by wasman            #+#    #+#             */
/*   Updated: 2016/11/08 18:23:37 by whickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 547

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

unsigned short		*is_valid(char *str);
int					classify(unsigned short value);
unsigned short		ft_btoi(char *str);
char				*readem(char *arg);
unsigned short		is_square(unsigned short tet);
unsigned short		is_vertical_straight(unsigned short tet);
unsigned short		is_horizontal_straight(unsigned short tet);
unsigned short		is_normal_t(unsigned short tet);
unsigned short		is_left_t(unsigned short tet);
unsigned short		is_right_t(unsigned short tet);
unsigned short		is_upside_down_t(unsigned short tet);
unsigned short		is_normal_j(unsigned short tet);
unsigned short		is_downward_j(unsigned short tet);
unsigned short		is_upside_down_j(unsigned short tet);
unsigned short		is_upward_j(unsigned short tet);
unsigned short		is_normal_z(unsigned short tet);
unsigned short		is_rotated_z(unsigned short tet);
unsigned short		is_normal_s(unsigned short tet);
unsigned short		is_rotated_s(unsigned short tet);
unsigned short		is_normal_l(unsigned short tet);
unsigned short		is_upward_l(unsigned short tet);
unsigned short		is_upside_down_l(unsigned short tet);
unsigned short		is_downward_l(unsigned short tet);
char				*itoa_base(int tet, int base);
void				print_solution(char **array);
char				*fix_offset(char *tet_string, int size);
char				**solve(char **tet, unsigned short *bit, char **sol);
char				*shift(char *tet_array, int size, int width);
int					get_width(unsigned short bitmap);
int					find_first_one_char(char *tet_array);
int					find_last_one_char(char *tet_array);
int					is_empty(char *tet, int size);
int					first_empty(char **square_str, int size);
int					fit_char(char *bitmap_str, char **square_str, int size);
char				**is_fit(char **t, unsigned short *bit, char **sol, int s);
int					nth_empty(char **square, int size, int ignore);
int					contact(char **solution, int number, int size);
char				**generate_shifts(char *tet_array, int size, int width);
int					num_of_tets(unsigned short *bitmap_array);
int					conflicts(char **conflicts, int i);
char				**assign_letters(char **solution);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnew(size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
#endif
