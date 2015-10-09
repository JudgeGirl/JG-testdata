P= solve
OBJECTS =
CFLAGS = -O2 -Wall -std=c99
LDLIBS = 
CC = c99

run:
	gcc-5 $(CFLAGS) solve.c -o solve

gen: gen.c
	gcc-5 gen.c -o gen
	./gen > 1.in
	./gen > 2.in
	./gen > 3.in
	./gen > 4.in
	./gen > 5.in

sol: solve.c
	gcc-5 $(CFLAGS) solve.c -o solve
	./solve < 1.in > 1.out
	./solve < 2.in > 2.out
	./solve < 3.in > 3.out
	./solve < 4.in > 4.out
	./solve < 5.in > 5.out
	
clean:
	rm solve
