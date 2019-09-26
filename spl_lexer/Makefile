CC=gcc
LIBS = -lfl
FLEX=flex

OBJS = helpler.o

lex.o: $(OBJS)
	$(FLEX) lex.l
	$(CC) lex.yy.c $(OBJS) $(LIBS) -o $@
	rm -f $(OBJS)

helpler.o: helpler.h

clean:
	@rm -f lex.yy.c $(OBJS)
.PHONY: clean
