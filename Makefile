##
## EPITECH PROJECT, 2020
## Project
## File description:
## Makefile
##

CC			= gcc
SRC			= $(wildcard src/main.c \
			src/event.c \
			src/mouse/mouse_management.c \
			src/init_obj_list.c \
			src/draw.c \
			src/clean.c \
			src/kill_sound.c \
			src/game_start.c \
			src/create_other.c \
			src/other.c \
			src/check_highscore.c \
			src/create_hearths.c \
			src/lose_menu.c \
			src/get_src.c \
			src/display_help.c \
			src/music.c \
			src/create_text.c \
			src/start_back.c \
			src/lib/create_window.c \
			src/lib/create_coor.c \
			src/lib/create_obj.c \
			src/lib/create_rect.c \
			src/lib/draw_obj.c \
			src/lib/move_frame.c \
			src/lib/update_object.c \
			src/lib/move_obj.c \
			src/lib/destroy_obj.c \
			src/lib/make_random.c \
			src/lib/my_getnbr.c \
			src/lib/my_strlen.c \
			src/lib/my_itoa.c \
			src/lib/my_strcat.c \
			src/lib/my_strcmp.c)
OBJ			= $(SRC:.c=.o)

CFLAGS		= -W -Wall -Wextra -g3
CPPFLAGS	= -ISFML_lib/
LDFLAGS		= -LSFML_lib/SFML -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio
TARGET		= game

all: 
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all