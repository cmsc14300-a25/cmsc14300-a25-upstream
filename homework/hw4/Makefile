OBJECTS = 
CFLAGS = -g -Wall -O3 --std=c11
LDLIBS= -l criterion -lm
CC=clang

all: student_test_image print_image_pixels

student_test_image: student_test_image.c image.c util.c

print_image_pixels: print_image_pixels.c util.c image.c

clean:
	rm -f student_test_image print_image_pixels
	rm -rf *.dSYM *~ \#* *.o
