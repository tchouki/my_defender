##
## EPITECH PROJECT, 2018
## makefile
## File description:
## compilation
##

### Colors
RED	=	\033[31m
GREEN	=	\033[32m
BLUE 	=	\033[34m
RESET	=	\033[0m
###

COMP	=	gcc

RM		=	rm -f

SRC		=	src/ally.c 					\
			src/background.c 			\
			src/character.c 			\
			src/destroy.c 				\
			src/draw_ground.c 			\
			src/draw_map.c 				\
			src/draw_wall.c 			\
			src/draw_wallback.c 		\
			src/enemy.c 				\
			src/events.c 				\
			src/game.c 					\
			src/hud.c 					\
			src/hud_text.c 				\
			src/hud_black.c 			\
			src/initialisation.c 		\
			src/life.c 					\
			src/list_ally.c 			\
			src/list_enemy.c 			\
			src/list_enemy_kill.c 		\
			src/main.c 					\
			src/market.c 				\
			src/mouse_functions.c 		\
			src/mouse_hovering.c 		\
			src/mouvement.c 			\
			src/mouvement_ally.c 		\
			src/mouvement_character.c 	\
			src/mouvement_enemy.c 		\
			src/my_putnbr.c 			\
			src/open_map.c 				\
			src/render.c 				\
			src/scene0.c 				\
			src/scene1.c 				\
			src/scene2.c 				\
			src/scene3.c 				\
			src/scene4.c 				\
			src/shop.c 					\
			src/shop_item.c 			\
			src/spike.c 				\
			src/trap.c 					\
			src/trap_effect.c 			\
			src/weapon.c 				\
			src/ultimate.c				\
			src/wizard_ultimate.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -I./include

LDFLAGS	+=	-lcsfml-system -lcsfml-graphics -lcsfml-window -lcsfml-audio -lm

#LDFLAGS +=	-lc_graph_prog -lm

NAME	=	my_defender

all:		$(NAME)
			@echo -e "$(GREEN)--------------------$(RESET)"
			@echo -e "$(GREEN)| $(RED)COMPILATION DONE $(GREEN)|$(RESET)"
			@echo -e "$(GREEN)--------------------$(RESET)"

debug:		CFLAGS += -g
debug:		re

$(NAME):	$(OBJ)
			$(COMP) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			$(RM) $(OBJ) vgcore.*

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:	all debug clean fclean re
