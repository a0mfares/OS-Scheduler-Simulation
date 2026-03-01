build:
	gcc "Process Generator/process_generator.c" -o process_generator.out
	gcc Clock/clk.c -o clk.out
	gcc "Test Generator/test_generator.c" -o test_generator.out
	gcc Process/process.c -o process.out
	gcc Scheduler/scheduler.c -o scheduler.out -lm
	

clean:
	rm -f *.out  processes.txt

all: clean build

run:
	./process_generator.out
