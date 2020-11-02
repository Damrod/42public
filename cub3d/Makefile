#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aollero- <aollero@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/20 13:50:10 by aollero-          #+#    #+#              #
#    Updated: 2020/10/12 19:06:36 by aollero-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = cub3D
CC = cc
SRCS = srcs/cub3d.c srcs/parse_isvalid.c srcs/parse_isvalid2.c				   \
	   srcs/parse_fields.c srcs/get_lines.c srcs/getncheck_map.c			   \
	   srcs/configure_map.c srcs/algebra_utils.c srcs/configure_sprites.c	   \
	   srcs/raycast2.c srcs/raycast1.c srcs/mng_imgs.c
OBJS = $(SRCS:%.c=%.o)
LIBSRCS =  libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c				   \
		  libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c			   \
		  libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c				   \
		  libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c			   \
		  libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c			   \
		  libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c				   \
		  libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c			   \
		  libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c			   \
		  libft/ft_strnstr.c libft/ft_strtrim.c	libft/ft_split_ultimate.c	   \
		  libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c			   \
		  libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c	   \
		  libft/ft_putnbr_fd.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c  \
		  libft/ft_lstclear.c libft/ft_lstdelone.c libft/ft_lstiter.c		   \
		  libft/ft_lstlast.c libft/ft_lstmap.c libft/ft_lstnew.c			   \
		  libft/ft_lstsize.c libft/get_next_line.c libft/ft_advalloc.c		   \
		  libft/ft_myalloc.c libft/ft_lstdelmany.c libft/ft_lsttoarr.c		   \
		  libft/ft_arrtolst.c libft/ft_findptrinarray.c libft/ft_mperror.c	   \
		  libft/ft_lstcullpattern.c libft/ft_strjoin_ult.c libft/misc.c		   \
		  libft/ft_isspace.c libft/ft_arrkey2.c libft/ft_arrkey.c			   \
		  libft/ft_arrbyte.c libft/mlx_protect.c libft/ft_array.c			   \
		  libft/ft_isspace_adv.c libft/ft_algebra.c libft/ft_strrchr.c
LIBOBJS = $(LIBSRCS:%.c=%.o)
INCS = incs/algebra_utils.h incs/cubconf.h incs/mng_imgs.h incs/raycast1.h	   \
	   incs/bmp.h incs/get_lines.h incs/parse_fields.h incs/raycast2.h		   \
	   incs/configure_map.h incs/getncheck_map.h incs/parse_isvalid2.h		   \
	   incs/configure_sprites.h incs/parse_isvalid.h
CFLAGS = -O3 -Wall -Werror -Wextra -Wno-unused-result	   \
		 -Wno-maybe-uninitialized
RM = rm -f
LDIR = libft/
MLXDIR = minilibx-linux/
SYSLIBDIR = /usr/lib/x86_64-linux-gnu/
SYSINCDIR = /usr/local/include/
LDLIBS = -lmlx -lX11 -lXext -lm

$(NAME) : $(SYSLIBDIR)libmlx.a $(OBJS) $(LIBOBJS) $(INCS)
		$(CC) $(CFLAGS) $^ $(LDLIBS) -L. -o $@

%.o : %.c
	$(CC) -c $(CFLAGS) $< $(LDLIBS) -o $@

$(LDIR)libmlx.a :
	cd minilibx-linux && ./configure && make -f Makefile.gen && \
	cp libmlx.a ../$(LDIR) && cp mlx.h ../incs

$(SYSLIBDIR)libmlx.a :
	make $(LDIR)libmlx.a
	sudo mv $(LDIR)libmlx.a $(SYSLIBDIR) && sudo mv incs/mlx.h $(SYSINCDIR)

install : $(SYSLIBDIR)libmlx.a

uninstall :
	sudo rm $(SYSLIBDIR)libmlx.a && sudo rm $(SYSINCDIR)mlx.h

all : $(NAME)

clean :
	$(RM) $(OBJS) $(LIBOBJS)
	@(( (( cd $(MLXDIR) && make clean )) || true )) 2> /dev/null
	@echo "cd $(MLXDIR) && make clean"

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LDIR)libft.a

re : fclean all

.PHONY : fclean clean re all install uninstall
