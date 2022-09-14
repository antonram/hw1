# Let's declare some variables
CC       = g++
CPPFLAGS = -Wall -g

all: ulliststr split
	-@echo "--- All Built!---"

split.o: split.cpp split.h
	$(CC) $(CPPFLAGS) -c split.cpp -o split.o

split: split.cpp split.o
	$(CC) $(CPPFLAGS) split_test.cpp split.o -o split

ulliststr.o: ulliststr.cpp ulliststr.h
	$(CC) $(CPPFLAGS) -c ulliststr.cpp -o ulliststr.o

ulliststr: ulliststr.cpp ulliststr.o
	$(CC) $(CPPFLAGS) ulliststr_test.cpp ulliststr.o -o ulliststr

.PHONY: clean tests

tests: ulliststr split
	-@./split
	-@./ulliststr
	-@echo "--- All Tested!---"

splitTests: split
	-@./split
	-@echo "--- Split Tested!---"

ulliststrTests: ulliststr
	-@./ulliststr
	-@echo "--- Ulliststr Tested!---"

clean:
	-@rm -rf ulliststr ulliststr.o
	-@rm -rf split split.o
	-@echo "--- All Clean!---"
