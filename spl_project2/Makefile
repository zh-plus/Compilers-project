
SRCS = main.cpp scanner.yy.cpp parser.tab.cpp spl_driver.cpp utils.cpp ast.cpp symbol.cpp type.cpp semantics.cpp visitor.cpp

SYMBOL_SRCS = test_symbol.cpp parser.tab.cpp ast.cpp symbol.cpp spl_driver.cpp scanner.yy.cpp utils.cpp type.cpp semantics.cpp

VISITOR_SRCS = test_visitor.cpp scanner.yy.cpp parser.tab.cpp spl_driver.cpp utils.cpp ast.cpp symbol.cpp type.cpp semantics.cpp visitor.cpp

TESTS = test1/test_1_r01.spl test1/test_1_r02.spl

bin/splc: $(SRCS)
	g++ -g -std=c++17 $(SRCS) -o $@

symbol: $(SYMBOL_SRCS)
	g++ -g -std=c++17 $(SYMBOL_SRCS) -o $@

visitor: $(VISITOR_SRCS)
	g++ -g -std=c++17 $(VISITOR_SRCS) -o $@

scanner.yy.cpp: scanner.l
	flex -o scanner.yy.cpp scanner.l

parser.tab.cpp: parser.y
	bison -t -d parser.y -o parser.tab.cpp

clean:
	rm -rf scanner.yy.cpp
	rm -rf parser.tab.cpp parser.tab.hpp stack.hh location.hh
	rm -rf splc

test1: bin/splc $(TESTS)
	./bin/splc test1/test_1_r01.spl > test1/test_1_r01.txt
	./bin/splc test1/test_1_r02.spl > test1/test_1_r02.txt
	./bin/splc test1/test_1_o01.spl > test1/test_1_o01.txt
	diff test1/test_1_r01.out test1/test_1_r01.txt
	diff test1/test_1_r02.out test1/test_1_r02.txt
	diff test1/test_1_o01.out test1/test_1_o01.txt

.PHONY: clean test