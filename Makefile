NAME			= push_swap
NAME_h			= $(NAME).h
BONUS_NAME		= checker
BONUS_NAME_h	= $(BONUS_NAME).h
SRC_PASS		= src/
SRCb_PASS		= src_bonus/
OTHER_PASS		= other/
STDSRC_PASS		= stdsrc/
SUBMIT_42		= git@vogsphere-v2.42tokyo.jp:vogsphere/intra-uuid-95d095c4-7428-4bfa-96a8-e4a103ba4267-4080568-blyu
SUBMIT_42d		= submit_to_42/
SUBMIT_d		= $(NAME)/
PRINTF_GIT		= https://github.com/bodu0204/ftprintf_o.git
PRINTF_od		= libftprintf_o/
PRINTF_a		= libftprintf.a
PRINTF_d		= libftprintf/
TEST_d			= test_case_0/
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I./

all : $(NAME)

$(NAME) : submitfile
	cd "$(SUBMIT_d)" && make all
	cp $(NAME) ./

bonus : $(NAME)
	cd "$(SUBMIT_d)" && make all
	cp $(BONUS_NAME) ./

push : fclean
	git add .
	git commit --allow-empty -m "commit form makefile"
	git push

cloneprintf :
	git clone $(PRINTF_GIT) $(PRINTF_od)
	cd "$(PRINTF_od)" && make submit
	rm -rf $(PRINTF_od)

submitfile : push clonelibft
	mkdir $(SUBMIT_d)
	cp $(SRC_PASS)* $(SUBMIT_d)
	cp $(SRCb_PASS)* $(SUBMIT_d)
	cp $(OTHER_PASS)* $(SUBMIT_d)
	mv $(PRINTF_d) $(SUBMIT_d)

submit : outclean submitfile
	mv $(SUBMIT_d) ../

file : fclean clonelibft
	mkdir $(SUBMIT_d)
	cp $(SRC_PASS)* $(SUBMIT_d)
	cp $(SRCb_PASS)* $(SUBMIT_d)
	cp $(OTHER_PASS)* $(SUBMIT_d)
	mv $(PRINTF_d) $(SUBMIT_d)

submit42 : push outclean submitfile
	git clone $(SUBMIT_42) $(SUBMIT_42d)
	rm -rf $(SUBMIT_42d)*
	cp -rf $(SUBMIT_d)* $(SUBMIT_42d)
	rm -rf $(SUBMIT_d)
	cd "$(PWD)/$(SUBMIT_42d)" && make push
	mv -rf $(SUBMIT_42d)
	echo "\n\nFinished push to 42.\n"

test0 : bonus
	mkdir

fclean :
	rm -rf $(SUBMIT_d)
	rm -rf $(PRINTF_d)
	rm -rf $(TEST_d)
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

outclean :
	rm -rf ../$(SUBMIT_d)
	rm -rf ../$(TEST_d)

allclean : fclean outclean

re : fclean all
