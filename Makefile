OBJECTS = $(DIR_O)/use_me_and_live_without_errors.o $(DIR_O)/quad_equ.o $(DIR_O)/debug_and_logs.o $(DIR_O)/main.o $(DIR_O)/func_numbers.o $(DIR_O)/input_or_output_function.o $(DIR_O)/test.o
CC = g++
CFLAGS = -c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
DIR_O = object
DIR_SOUR = source

kotik.exe: $(OBJECTS)
	$(CC) $(OBJECTS)  -o object/kotik.exe

$(DIR_O)/use_me_and_live_without_errors.o: $(DIR_SOUR)/use_me_and_live_without_errors.cpp $(DIR_SOUR)/use_me_and_live_without_errors.h
	$(CC) $(CFLAGS) $< -o $@

$(DIR_O)/main.o: $(DIR_SOUR)/main.cpp $(DIR_SOUR)/test.h $(DIR_SOUR)/quad_equ.h $(DIR_SOUR)/debug_and_logs.h $(DIR_SOUR)/use_me_and_live_without_errors.h
	$(CC) $(CFLAGS) $< -o $@

$(DIR_O)/quad_equ.o: $(DIR_SOUR)/quad_equ.cpp $(DIR_SOUR)/input_or_output_function.h $(DIR_SOUR)/debug_and_logs.h $(DIR_SOUR)/func_numbers.h $(DIR_SOUR)/quad_equ.h $(DIR_SOUR)/use_me_and_live_without_errors.h
	$(CC) $(CFLAGS) $< -o $@

$(DIR_O)/func_numbers.o: $(DIR_SOUR)/func_numbers.cpp $(DIR_SOUR)/quad_equ.h $(DIR_SOUR)/func_numbers.h $(DIR_SOUR)/use_me_and_live_without_errors.h
	$(CC) $(CFLAGS) $< -o $@

$(DIR_O)/input_or_output_function.o: $(DIR_SOUR)/input_or_output_function.cpp $(DIR_SOUR)/input_or_output_function.h $(DIR_SOUR)/quad_equ.h
	$(CC) $(CFLAGS) $< -o $@

$(DIR_O)/debug_and_logs.o: $(DIR_SOUR)/debug_and_logs.cpp $(DIR_SOUR)/debug_and_logs.h $(DIR_SOUR)/use_me_and_live_without_errors.h
	$(CC) $(CFLAGS) $< -o $@

$(DIR_O)/test.o: $(DIR_SOUR)/test.cpp $(DIR_SOUR)/test.h $(DIR_SOUR)/use_me_and_live_without_errors.h $(DIR_SOUR)/quad_equ.h $(DIR_SOUR)/func_numbers.h $(DIR_SOUR)/debug_and_logs.h $(DIR_SOUR)/input_or_output_function.h
	$(CC) $(CFLAGS) $< -o $@

docs:
	@doxygen
