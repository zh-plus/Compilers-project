//
// Created by 10578 on 11/5/2019.
//

#include "type.hpp"

#include <utility>
#include "ast.hpp"

namespace SPL {
    using namespace std;

    ostream &operator<<(ostream &os, const Type &obj) {
        os << obj.to_string();
        return os;
    }

    Primitive_Type::Primitive_Type(Leaf_Node *leaf) {
        if (leaf->leaf_type != token_type::TYPE) {
            cout << "The type class should be initialized from TYPE Leaf_Node!" << endl;
            exit(EXIT_FAILURE);
        }

        string type_name = leaf->get_lexeme();
        type = [&]() {
            if (type_name == "int") {
                return primitive_type::INT;
            } else if (type_name == "float") {
                return primitive_type::FLOAT;
            } else if (type_name == "char") {
                return primitive_type::CHAR;
            } else {
                cout << "The TYPE Leaf_Node should be one of [int, float, char]!" << endl;
                exit(EXIT_FAILURE);
            }
        }();

        line_no = leaf->line_no;
    }

    Primitive_Type::Primitive_Type(token_type t_type) {
        switch (t_type) {
            case token_type::INT:
                type = primitive_type::INT;
                break;
            case token_type::CHAR:
                type = primitive_type::CHAR;
                break;
            case token_type::FLOAT:
                type = primitive_type::FLOAT;
                break;
        }
    }

    bool Primitive_Type::compassionate(Type *other) {
        if (other == nullptr) {
            return false;
        }

        auto p_other = dynamic_cast<Primitive_Type *>(other);
        if (p_other == nullptr) {
            return false;
        }

        return type == p_other->type;
    }

    Array_Type::Array_Type(Type *base_type, Array_VarDec_Node *array_node) {
        line_no = base_type->line_no;
        m_base_type = base_type;

        VarDec_Node *var_dec = array_node;
        while (!var_dec->is_atomic()) {
            shape.push_back(stoi(dynamic_cast<Array_VarDec_Node *>(var_dec)->_int->get_lexeme()));
            var_dec = dynamic_cast<Array_VarDec_Node *>(var_dec)->var_dec;
        }

        std::reverse(shape.begin(), shape.end());
    }

    bool Array_Type::compassionate(Type *other) {
        if (other == nullptr) {
            return false;
        }

        auto a_other = dynamic_cast<Array_Type *>(other);
        if (a_other == nullptr) {
            return false;
        }

        return m_base_type->compassionate(a_other->m_base_type) && same_shape_of(a_other);
    }

    bool Array_Type::same_shape_of(Array_Type * other_shape) {
        return std::equal(shape.begin(), shape.end(), other_shape->shape.begin());
    }

    Type *Array_Type::reduce_dim() {
        if (shape.size() == 1) {
            return m_base_type;
        }

        vector<int> new_shape(shape.begin() + 1, shape.end());
        return new Array_Type(m_base_type, new_shape);
    }

    Array_Type::Array_Type(Type *base_type, std::vector<int> shape) {
        this->m_base_type = base_type;
        this->shape = std::move(shape);
    }


    Struct_Type::Struct_Type(std::string id, int line_no, std::vector<std::pair<std::string, Type *>> member_vector) {
        this->struct_id = id;
        this->line_no = line_no;

        for (auto &p: member_vector) {
            members.insert(p);
        }
    }

    bool Struct_Type::compassionate(Type *other) {
        if (other == nullptr) {
            return false;
        }

        auto s_other = dynamic_cast<Struct_Type *>(other);
        if (s_other == nullptr) {
            return false;
        }

        return this->struct_id == s_other->struct_id;
    }

    bool Struct_Type::contains(const std::string id) {
        return members.find(id) != members.end();
    }

}
