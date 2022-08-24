NAME = libftprintf.a

HEADER = ft_printf.h

HEADER_BONUS = ft_printf_bonus.h

LIST =  ft_printf.c ft_print_c.c ft_print_string.c ft_print_integer.c \
        ft_print_unsint.c ft_print_x.c ft_print_address.c ft_print_precent.c \
		ft_width_prec_type.c ft_print_string_help.c ft_print_xxx.c ft_print_integer_help.c

LIST_BONUS = ft_printf_bonus.c ft_print_c_bonus.c ft_print_string_bonus.c ft_print_integer_bonus.c \
        ft_print_unsint_bonus.c ft_print_x_bonus.c ft_print_address_bonus.c ft_print_precent_bonus.c \
		ft_width_prec_type_bonus.c ft_print_string_help_bonus.c ft_print_xxx_bonus.c ft_print_integer_help_bonus.c

OBJS = $(patsubst %.c,%.o,$(LIST))

OBJS_BONUS = $(patsubst %.c,%.o,$(LIST_BONUS))

FLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re bonus

all : $(NAME) $(HEADER)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $?

%.o : %.c ft_printf.h
	CC $(FLAGS) -c $< -o $@ -I ${HEADER}

%.o : %.c ft_printf_bonus.h
	CC $(FLAGS) -c $< -o $@ -I ${HEADER_BONUS}

bonus : $(OBJS_BONUS) 
	ar rcs $(NAME) $(OBJS_BONUS)

clean :
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	@rm -f $(NAME) 

re : fclean all