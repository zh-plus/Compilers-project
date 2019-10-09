//
// Created by 10578 on 10/9/2019.
//

#ifndef __AST_HPP__
#define __AST_HPP__

#include <iostream>
#include <utility>
#include <vector>
#include <string>

/**
 * Abstract syntax tree of SUSTech Programming Language.
 */

namespace SPL {

    class AST_Node {
    public:
        virtual ~AST_Node();
    };

    class ASSIGN_Node : AST_Node {
    public:
        ~ASSIGN_Node() override;

        ASSIGN_Node(std::string id, int value) : id{std::move(id)}, value{value} {};

    private:
        std::string id;
        int value;
    };

    class ARGS_Node : AST_Node {
    public:
        ~ARGS_Node() override;

        ARGS_Node(std::string id, int value) : id{std::move(id)}, value{value} {
            std::cout << "ARGS Node initialized!" << std::endl;
        };

        void push_back(std::string id);

    private:
        std::string id;
        int value;
    };
}


#endif //__AST_HPP__
