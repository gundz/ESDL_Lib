NAME =			libesdl.a

SRCS =			\
				esdl_init.c \
				esdl_events.c \
				esdl_fps.c \
				esdl_draw.c \
				esdl_color.c \
				esdl_surface.c \
				esdl_images.c \

#TYPE: LIB or PROGRAM
TYPE =			LIB

#OS: LINUX/OSX or WINDOWS
OS =			LINUX

UNIX_CC =		gcc
WIN_CC =		i686-w64-mingw32-gcc

EXTENTION =		c

CFLAGS =		-Wall -Werror -Wextra

#LIB_NAMES =		-lfoo -lbar
#LIB_PATH =		./libfoo/ ./libbar/

ifeq ($(OS), WINDOWS)
SDL2_WIN_PATH =		$(shell pwd)/SDL2
LIB_SUPP_INC =		`SDL2/bin/sdl2-config --prefix=$(SDL2_WIN_PATH) --cflags`
LIB_SUPP =		`SDL2/bin/sdl2-config --prefix=$(SDL2_WIN_PATH) --libs` -lSD2_image
NAME := $(NAME)
CC = $(WIN_CC)
else
LIB_SUPP_INC =		`sdl2-config --cflags`
LIB_SUPP =		`sdl2-config --libs` -lSDL2_image
CC =			$(UNIX_CC)
endif


SRC_PATH = 		./srcs/
INC_PATH = 		./includes/
OBJ_PATH =		./obj/

OBJ_NAME = $(SRCS:.$(EXTENTION)=.o)
SRC = $(addprefix $(SRC_PATH), $(SRCS))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIB = $(addprefix -I, $(addsuffix includes, $(LIB_PATH))) $(addprefix -L, $(LIB_PATH))
INC = $(addprefix -I, $(INC_PATH))
INC += $(LIB_SUPP_INC)
LDFLAGS = $(LIB) $(LIB_NAMES)
EMPTY =

all: libs name $(OBJ) done $(NAME)

name :
	@ echo "\033[4;7mCompiling Objects:\033[0m "

done :
	@ echo "\n\033[4m\033[95md\033[93mo\033[32mn\033[96me\033[0m \033[91m!\033[0m\n"

$(NAME): $(OBJ)
	@ echo "\033[4;7mCompiling:\033[0m [$(NAME)]"
ifeq ($(TYPE), LIB)
	@ ar -rc $(NAME) $(OBJ)
	@ ranlib $(NAME)
else
	@ $(CC) $(OBJ) $(LDFLAGS) $(LIB_SUPP) -o $(NAME)
endif
	@ echo "\033[4m\033[95md\033[93mo\033[32mn\033[96me\033[0m \033[91m!\033[0m\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.$(EXTENTION)
	@ echo -n "\033[37;7m+\033[0m"
	@ mkdir -p $(OBJ_PATH) 2> /dev/null
	@ $(CC) $(CFLAGS) $(LIB) $(INC) -c $< -o $@

ifeq ($(LIB_PATH), $(EMPTY))
else
libs:
	@ $(foreach lib, $(LIB_PATH), make -C $(lib);)
endif

clean:
	@ rm -rf $(OBJ_PATH)
	@ echo "\033[4;7mCleaning:\033[0m [$(NAME)]\n\033[4m\033[95md\033[93mo\033[32mn\033[96me\033[0m \033[91m!\033[0m\n"
ifeq ($(LIB_PATH), $(EMPTY))
else
	@ $(foreach lib, $(LIB_PATH), make clean -C $(lib);)
endif

fclean: clean
	@ rm -f $(NAME)
	@ echo "\033[4;7mFcleaning:\033[0m [$(NAME)]\033[0m\n\033[4m\033[95md\033[93mo\033[32mn\033[96me\033[0m \033[91m!\033[0m\n"
ifeq ($(LIB_PATH), $(EMPTY))
else
	@ $(foreach lib, $(LIB_PATH), make fclean -C $(lib);)
endif

re: fclean all

.PHONY: all clean fclean re libs
