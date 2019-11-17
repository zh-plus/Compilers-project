//
// Created by 10578 on 2019/11/17.
//

#ifndef __INFORMATION_HPP__
#define __INFORMATION_HPP__

namespace SPL {
    /* Forward Declaration */
    class Type;

    class Scan_Info {
    public:
        std::string lexeme;
        int line_no;

        Scan_Info(std::string lexeme, int line) : lexeme{lexeme}, line_no{line} {};
    };

    class Exp_Info {
    public:
        bool is_rvalue;

        Type *exp_type;

    };
}

#endif //__INFORMATION_HPP__
