# CC for the compiler name
# CFLAGS for the compiler options
# OBJS is a list of all object files
CC=g++
CFLAGS=-c 
OBJS=builder.o event.o linkedlist.o stack.o structuretype.o builders.o
INCLUDES=builder.h event.h linkedlist.h stack.h structuretype.h

prog: $(OBJS) 
	$(CC) $(OBJS) -o prog
    
%.o: %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) $<;
    
clean:
	rm *.o prog