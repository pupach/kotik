OBJECTS = quad_equ.o const.o debug_and_logs.o main.o func_numbers.o input_or_output_function.o test.o
CC=g++
CFLAGS= -c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE


all:kotik.exe

kotik.exe: $(OBJECTS)
	$(CC) $(OBJECTS) -o kotik.exe

const.o: const.cpp const.h
	$(CC) $(CFLAGS) const.cpp 

main.o: main.cpp test.h quad_equ.h debug_and_logs.h const.h
	$(CC) $(CFLAGS) main.cpp

quad_equ.o: quad_equ.cpp input_or_output_function.h debug_and_logs.h func_numbers.h quad_equ.h const.h
	$(CC) $(CFLAGS) quad_equ.cpp

func_numbers.o: func_numbers.cpp quad_equ.h func_numbers.h const.h
	$(CC) $(CFLAGS) func_numbers.cpp

input_or_output_function.o: input_or_output_function.cpp input_or_output_function.h quad_equ.h const.h
	$(CC) $(CFLAGS) input_or_output_function.cpp

debug_and_logs.o: debug_and_logs.cpp debug_and_logs.h const.h
	$(CC) $(CFLAGS) debug_and_logs.cpp 

test.o: test.cpp test.h const.h quad_equ.h func_numbers.h debug_and_logs.h input_or_output_function.h
	$(CC) $(CFLAGS) test.cpp
