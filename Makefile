################################################################################
# Basics #######################################################################
NAME	:=	ft_select
OPT		:=	
CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror

DEBUG_FLAG	:=	-g
FSA_FLAGS	:=	$(DEBUG_FLAG) -fsanitize=address
VAL_FLAGS	:=	--leak-check=full --track-origins=yes --show-leak-kinds=all \
				--show-reachable=no

# Libraries ####################################################################
LIBFT_DIR		:=	libft
LIBTERM_DIR		:=	libterm

LIB_INCL		:=	-L $(LIBFT_DIR) -lft -L $(LIBTERM_DIR) -lterm -ltermcap

LIBFT_A			:=	$(addprefix $(LIBFT_DIR)/,libft.a)
LIBTERM_A		:=	$(addprefix $(LIBTERM_DIR)/,libterm.a)

LIBS			:= $(LIBFT_A) $(LIBTERM_A)

# Includes #####################################################################
INCL_DIR	:=	includes libft/includes libterm/includes
INCL_CMD	:=	$(addprefix -I,$(INCL_DIR))

INCL_FILES	:=	ft_select.h

INCLS		:=	$(addprefix includes/,$(INCL_FILES))

# Directories ##################################################################
SRC_DIR	:=	srcs
	#srcs subdirectories names
	COLORS_DIR		:= colors
	COMMANDS_DIR	:= commands
	ERRORS_DIR		:= errors
	PRINTS_DIR		:= prints
	SIGNALS_DIR		:= signals
	#list of all srcs subdirectories
	SRC_SUBDIRS	:=	$(COLORS_DIR) $(COMMANDS_DIR) $(ERRORS_DIR) $(PRINTS_DIR) \
					$(SIGNALS_DIR)

#VPATH specifies a list of directories that 'make' should search
VPATH	:=	$(SRC_DIR) $(addprefix $(SRC_DIR)/,$(SRC_SUBDIRS))

# Srcs file names ##############################################################
SRC_FILES	:=	free.c linked_list.c main.c
	#srcs subfiles names
	ERRORS_FILES	:=	error_usage.c
	COLORS_FILES	:=	colors.c filetype.c
	COMMANDS_FILES	:=	arrows.c check_commands.c deletor.c selector.c
	PRINTS_FILES	:=	info_utils.c print_utils.c printing.c
	SIGNALS_FILES	:=	signal_utils.c signals.c

#list of all .c files
C_FILES	:=	$(SRC_FILES) $(COLORS_FILES) $(COMMANDS_FILES) $(ERRORS_FILES) \
			$(PRINTS_FILES) $(SIGNALS_FILES)


# Complete path of each .c files ###############################################
SRC_PATH		:=	$(addprefix $(SRC_DIR)/,$(SRC_FILES))
ERRORS_PATH		:=	$(addprefix $(ERRORS_DIR)/,$(ERRORS_FILES))
COLORS_PATH		:=	$(addprefix $(COLORS_DIR)/,$(COLORS_FILES))
PRINTS_PATH		:=	$(addprefix $(PRINTS_DIR)/,$(PRINTS_FILES))
SIGNALS_PATH	:=	$(addprefix $(SIGNALS_DIR)/,$(SIGNALS_FILES))
COMMANDS_PATH	:=	$(addprefix $(COMMANDS_DIR)/,$(COMMANDS_FILES))

#list of all "path/*.c"
SRCS	:=	$(addprefix $(SRC_DIR)/,$(ERRORS_PATH))		\
			$(addprefix $(SRC_DIR)/,$(COLORS_PATH))		\
			$(addprefix $(SRC_DIR)/,$(COMMANDS_PATH))	\
			$(addprefix $(SRC_DIR)/,$(PRINTS_PATH))		\
			$(addprefix $(SRC_DIR)/,$(SIGNALS_PATH))	\
			$(SRC_PATH)	

#Object ########################################################################
OBJ_DIR		:=	objs
OBJ_FILES	:=	$(C_FILES:.c=.o)
OBJS		:=	$(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

# Rules ########################################################################
.PHONY: all fsa val rmh adh tag clean fclean re d norm test ask_libft \
	ask_libterm ask_libs

all: ask_libs $(NAME) tag Makefile

ask_libs: ask_libft ask_libterm

ask_libft:
	@$(MAKE) -qC libft ; if [ $$? != "0" ] ; then\
		$(MAKE) -j -C libft;\
		fi

ask_libterm:
	@$(MAKE) -qC libterm child; if [ $$? != "0" ] ; then\
		$(MAKE) -j -C libterm;\
		else\
			echo "au revoir";\
		fi

$(LIBS): ask_libs

fsa: $(SRCS) $(LIBS)
	$(CC) $(CFLAGS) $(FSA_FLAGS) $(INCL_CMD) $(LIB_INCL) $(SRCS) -o $(NAME)
	$(OPT) ./$(NAME)

val: $(SRCS) $(LIBS)
	$(CC) $(DEBUG_FLAG) $(INCL_CMD) $(LIB_INCL) $^ -o $(NAME)
	valgrind $(VAL_FLAGS) $(OPT) ./$(NAME)

rmh:
	./script/42header_c_rm.sh $(SRCS) $(INCLS)

adh: rmh
	vim -ns script/42header_add.keys $(SRCS) $(INCLS)

$(NAME): $(OBJS) libterm/libterm.a libft/libft.a
	$(CC) $(CFLAGS) $(INCL_CMD) $^ -o $@ $(LIB_INCL)

$(OBJ_DIR)/%.o: %.c
	@mkdir $(OBJ_DIR) 2> /dev/null || true
	@$(CC) $(CFlAGS) $(INCL_CMD) -o $@ -c $<
	@echo Compiling $@

tag:
	@ctags -R .

clean: 
	$(MAKE) clean -C libft
	$(MAKE) clean -C libterm
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C libterm
	$(RM) $(NAME)
	$(RM) -r $(NAME).dSYM

re: fclean all

d: all
	$(OPT) ./$(NAME)


norm: adh
	norminette $(SRCS)
	norminette $(INCLS)

test:
	@echo "-----------------------------------"
	$(MAKE) -qC libft/ ; echo answer=$$?
