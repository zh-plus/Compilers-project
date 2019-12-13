//
// Created by 10578 on 12/4/2019.
//

#ifndef __TAC_HPP__
#define __TAC_HPP__

#include <utility>

#include "type.hpp"

namespace SPL {
    class Label {
    public:
        std::string name;

        Label() {
            name = "label_" + std::to_string(get_number());
        };

        [[nodiscard]] std::string to_string() const {
            return name;
        }

        static int get_number() {
            return number++;
        }

    private:
        static int number;
    };

    class Quadruple {
    public:
        virtual ~Quadruple() = default;

        [[nodiscard]] virtual std::string to_string() const = 0;
    };

    class Label_Quadru : public Quadruple {
    public:
        explicit Label_Quadru(Label *label) : label{label} {}

        ~Label_Quadru() override {
            delete label;
        }

    private:
        Label *label;
    };

    class Func_Quadru : public Quadruple {
    public:
        explicit Func_Quadru(std::string name) : name{std::move(name)} {}

    private:
        std::string name;
    };

    class Assign_Quadru : public Quadruple {
    public:
        [[nodiscard]] std::string to_string() const override;

    protected:
        std::string rhs;
        std::string lhs;
    };

    class Assign_Value_Quadru : public Assign_Quadru {
    public:
        Assign_Value_Quadru(const std::string &lhs, const std::string &rhs);
    };

    class Assign_Address_Quadru : public Assign_Quadru {
    public:
        Assign_Address_Quadru(const std::string &lhs, const std::string &rhs);
    };

    class Assign_Deref_Quadru : public Assign_Quadru {
    public:
        Assign_Deref_Quadru(const std::string &lhs, const std::string &rhs);
    };

    class Deref_Assign_Quadru : public Assign_Quadru {
    public:
        Deref_Assign_Quadru(const std::string &lhs, const std::string &rhs);
    };

    class Arith_Quadru : public Quadruple {
    public:
        Arith_Quadru(std::string lhs, std::string arg1, std::string arg2, op_type op)
                : lhs{std::move(lhs)}, arg1{std::move(arg1)}, arg2{std::move(arg2)}, op{op} {};

        Arith_Quadru(std::string lhs, std::string arg1, std::string arg2, token_type op)
                : lhs{std::move(lhs)}, arg1{std::move(arg1)}, arg2{std::move(arg2)} {
//            this.op = [] () {
//                switch (op) {
//                    token_type::PLUS: return op_type::ADD
//                }
//            }();


        };

        [[nodiscard]] std::string to_string() const override;

    private:
        std::string lhs;
        std::string arg1;
        std::string arg2;
        op_type op;
    };

    class Goto_Quadru : public Quadruple {
    public:
        explicit Goto_Quadru(Label *label) : label{label} {};

        ~Goto_Quadru() override {
            delete label;
        }

        [[nodiscard]] std::string to_string() const override;

    private:
        Label *label;
    };

    class CGoto_Quadru : public Quadruple {
    public:
        CGoto_Quadru(std::string arg1, std::string arg2, op_type op, Label *label)
                : arg1{std::move(arg1)}, arg2{std::move(arg2)}, op{op}, label{label} {};

        ~CGoto_Quadru() override {
            delete label;
        }

        [[nodiscard]] std::string to_string() const override;

    private:
        std::string arg1;
        std::string arg2;
        op_type op;
        Label *label;
    };

    class Return_Quadru : public Quadruple {
    public:
        explicit Return_Quadru(std::string name) : name{std::move(name)} {};

        [[nodiscard]] std::string to_string() const override;

    private:
        std::string name;
    };

    class Dec_Quadru : public Quadruple {
    public:
        Dec_Quadru(std::string name, int size) : name{std::move(name)}, size{size} {};

        [[nodiscard]] std::string to_string() const override;

    private:
        std::string name;
        int size;
    };

    class Param_Quadru : public Quadruple {
    public:
        explicit Param_Quadru(std::string name) : name{std::move(name)} {};

        [[nodiscard]] std::string to_string() const override;

    private:
        std::string name;
    };

    class Arg_Quadru : public Quadruple {
    public:
        explicit Arg_Quadru(std::string name) : name{std::move(name)} {};

        [[nodiscard]] std::string to_string() const override;

    private:
        std::string name;
    };

    class Call_Quadru : public Quadruple {
    public:
        Call_Quadru(std::string lhs, std::string func_name)
                : lhs{std::move(lhs)}, func_name{std::move(func_name)} {};

        [[nodiscard]] std::string to_string() const override;

    private:
        std::string lhs;
        std::string func_name;
    };

    class Read_Quadru : public Quadruple {
    public:
        explicit Read_Quadru(std::string name) : name{std::move(name)} {};

        [[nodiscard]] std::string to_string() const override;

    private:
        std::string name;
    };

    class Write_Quadru : public Quadruple {
    public:
        explicit Write_Quadru(std::string name) : name{std::move(name)} {};

        [[nodiscard]] std::string to_string() const override;

    private:
        std::string name;
    };

    class TAC {
    public:
        ~TAC() {
            for (auto &&ptr: instructions) {
                delete ptr;
            }
        }

        void extend(const TAC &other);

        void add(Quadruple *quadruple);

        std::vector<Quadruple *> instructions;
    };

}


#endif //__TAC_HPP__
