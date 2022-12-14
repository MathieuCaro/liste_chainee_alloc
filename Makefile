CC ?= gcc
CFLAGS += -Wall --pedantic -Werror
DEBUG_FLAGS += -g
CFILES = linked_list.c 


lib:
	$(CC) -fPIC -c $(CFLAGS) $(CFILES)
	$(CC) -shared -o liblinkedlist.so *.o

clean:
	rm -f *.o linked_list_tests linked_list *.so
