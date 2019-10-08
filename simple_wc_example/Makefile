mc:
	flex -o mc_lexer.yy.cpp mc_lexer.l
	bison -t -d mc_parser.yy -o mc_parser.tab.cpp
	g++ -g -std=c++17 main.cpp mc_lexer.yy.cpp mc_parser.tab.cpp mc_driver.cpp -o $@

clean:
	rm -rf mc_lexer.yy.cpp
	rm -rf mc_parser.tab.cpp mc_parser.tab.hpp
	rm -rf mc

.PHONY: clean
