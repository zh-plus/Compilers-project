splc:
	flex -o scanner.yy.cpp scanner.l
	bison -t -d parser.y -o parser.tab.cpp
	g++ -g -std=c++17 splc.cpp scanner.yy.cpp parser.tab.cpp helpler.cpp -o $@

clean:
	rm -rf scanner.yy.cpp
	rm -rf parser.tab.cpp parser.tab.hpp
	rm -rf a.out

.PHONY: clean
