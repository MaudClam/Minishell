# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 01:18:20 by mclam             #+#    #+#              #
#    Updated: 2021/09/19 01:18:20 by mclam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

SRCS =		ft_arrsize.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_calloc_lc.c \
			ft_error_functions.c \
			ft_fi.c \
			ft_indexname_lc.c \
			ft_is_functions.c \
			ft_is_functions1.c \
			ft_itoa_lc.c \
			ft_lc.c \
			ft_lc1.c \
			ft_lst_functions.c \
			ft_lst_functions1.c \
			ft_mem_functions.c \
			ft_memcpy.c \
			ft_put_functions.c \
			ft_splitset_lc.c \
			ft_str_functions.c \
			ft_str_functions1.c \
			ft_strdup_lc.c \
			ft_strdup.c \
			ft_strjoin_lc.c \
			ft_strtrim_lc.c \
			ft_substr_lc.c \
			ft_substr.c \
			ft_tolowerupper.c

OBJS =		$(SRCS:.c=.o)

HEADER =	libft.h

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

.c.o:		%.c $(HEADER)
			$(CC) $(CFLAGS) $(TEST) -c $< -o $(<:.c=.o)

all:		$(NAME)
			@echo "Make done"

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS) $(HEADER)
			ranlib $(NAME)

clean:
			@rm -f $(OBJS) $(HEADER).gch
			@echo "Make clean done"

fclean:		clean
			@rm -f $(NAME)
			@echo "Make fclean done"

re:			fclean all

norm:
			norminette *.c *.h

.PHONY:		all clean fclean re norm

