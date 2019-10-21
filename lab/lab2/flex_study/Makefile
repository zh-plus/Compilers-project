CC=gcc
FLEX=flex
wc:
	$(FLEX) lex.l
	$(CC) lex.yy.c -lfl -o study.out
clean:
	@rm -f lex.yy.c *.out
.PHONY: wc
