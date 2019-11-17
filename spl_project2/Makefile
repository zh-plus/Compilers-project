
SRCS = main.cpp scanner.yy.cpp parser.tab.cpp spl_driver.cpp utils.cpp ast.cpp symbol.cpp type.cpp semantics.cpp visitor.cpp error.cpp information.cpp

GRAMMAR_SRCS = test_project1.cpp parser.tab.cpp ast.cpp symbol.cpp spl_driver.cpp scanner.yy.cpp utils.cpp type.cpp semantics.cpp visitor.cpp error.cpp information.cpp

VISITOR_SRCS = test_visitor.cpp scanner.yy.cpp parser.tab.cpp spl_driver.cpp utils.cpp ast.cpp symbol.cpp type.cpp semantics.cpp visitor.cpp error.cpp information.cpp

bin/splc: $(SRCS)
	g++ -g -std=c++17 $(SRCS) -o $@

grammar: $(GRAMMAR_SRCS)
	g++ -g -std=c++17 $(GRAMMAR_SRCS) -o $@

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

test2: bin/splc
	./bin/splc test/test_2_o01.spl
	./bin/splc test/test_2_o02.spl
	./bin/splc test/test_2_r01.spl
	./bin/splc test/test_2_r02.spl
	./bin/splc test/test_2_r03.spl
	./bin/splc test/test_2_r04.spl
	./bin/splc test/test_2_r05.spl
	./bin/splc test/test_2_r06.spl
	./bin/splc test/test_2_r07.spl
	./bin/splc test/test_2_r08.spl
	./bin/splc test/test_2_r09.spl
	./bin/splc test/test_2_r10.spl
	./bin/splc test/test_2_r11.spl
	./bin/splc test/test_2_r12.spl
	./bin/splc test/test_2_r13.spl
	./bin/splc test/test_2_r14.spl
	./bin/splc test/test_2_r15.spl
	diff test/test_2_o01.out test/ans/test_2_o01.out
	diff test/test_2_o02.out test/ans/test_2_o02.out
	diff test/test_2_r01.out test/ans/test_2_r01.out
	diff test/test_2_r02.out test/ans/test_2_r02.out
	diff test/test_2_r03.out test/ans/test_2_r03.out
	diff test/test_2_r04.out test/ans/test_2_r04.out
	diff test/test_2_r05.out test/ans/test_2_r05.out
	diff test/test_2_r06.out test/ans/test_2_r06.out
	diff test/test_2_r07.out test/ans/test_2_r07.out
	diff test/test_2_r08.out test/ans/test_2_r08.out
	diff test/test_2_r09.out test/ans/test_2_r09.out
	diff test/test_2_r10.out test/ans/test_2_r10.out
	diff test/test_2_r11.out test/ans/test_2_r11.out
	diff test/test_2_r12.out test/ans/test_2_r12.out
	diff test/test_2_r13.out test/ans/test_2_r13.out
	diff test/test_2_r14.out test/ans/test_2_r14.out
	diff test/test_2_r15.out test/ans/test_2_r15.out

test1: grammar $(TESTS)
	./grammar test1/test_1_r01.spl > test1/test_1_r01.txt
	./grammar test1/test_1_r02.spl > test1/test_1_r02.txt
	./grammar test1/test_1_o01.spl > test1/test_1_o01.txt
	diff test1/test_1_r01.out test1/test_1_r01.txt
	diff test1/test_1_r02.out test1/test_1_r02.txt
	diff test1/test_1_o01.out test1/test_1_o01.txt

.PHONY: clean test