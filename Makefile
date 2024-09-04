CC = gcc -std=c11
CFLAGS = -Wall -Wextra -Werror -std=c11


OS := $(shell uname)
ifeq ($(OS), Darwin)
 TEST_FLAGS = -lcheck -lm -lpthread
else
 TEST_FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
endif


all: s21_math.a test gcov_report

s21_math.a:
	$(CC) -c $(CFLAGS) s21_math.c -o s21_math.o
	ar rc s21_math.a s21_math.o

style:
	clang-format -style=Google -n *.c *.h
	clang-format -style=Google -i *.c *.h

test: s21_math.a
	 gcc $(CFLAGS) test.c s21_*.c -o test $(TEST_FLAGS)


gcov_report: s21_math.a
	$(CC) $(CFLAGS)  $(TEST_FLAGS) *.c --coverage  -o test
	./test
	gcov s21_math.c
	lcov -t "proverka" -o result.info -c -d .
	genhtml -o report result.info
	open report/index.html

lcov:
	brew install lcov

brew:
	cd
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

clean:
	rm -f s21_math
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcov

rebuild: clean s21_math.a
