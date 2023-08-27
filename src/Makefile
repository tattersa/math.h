CC = gcc
STDFLAGS = -Wall -Wextra -Werror -std=c11
GCOVFLAGS = -fprofile-arcs -ftest-coverage -L


UNAME = $(shell uname -s)
ifeq ($(UNAME),Darwin)
	LIBFLAGS = -lcheck -lm -lpthread
	OPEN = open
endif
ifeq ($(UNAME),Linux)
	LIBFLAGS = -lcheck -lm -lpthread -lrt -lsubunit
endif


all: s21_math.a 

test: s21_math.a
	$(CC) $(STDFLAGS) test.c s21_math.a $(LIBFLAGS) -o test.out 
	./test.out

s21_math.a:
	$(CC) $(STDFLAGS) -c  s21_*.c 
	ar rcs s21_math.a *.o
	ranlib s21_math.a



gcov_report: s21_math.a
	$(CC) $(GCOVFLAGS) $(STDFLAGS) test.c $(LIBGLAGS) s21*.c -o GcovReport
	./GcovReport
	lcov -t "GcovReport" -o GcovReport.info -c -d .
	genhtml -o report GcovReport.info
	$(OPEN) ./report/index-sort-f.html



lint:
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c *.h *.c
	rm CPPLINT.cfg


valgrind: test
	valgrind --leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--verbose \
	--log-file=valgrind-out.txt \
	./s21_string_test

cppcheck:
	cppcheck --enable=all --inconclusive *.c *.h

clean: 
	rm -rf *.gcda *.gcno *.gcov *.a *.o ./report *.info

rebuild: clean all
