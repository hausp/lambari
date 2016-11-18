
#ifndef FALK_OPERATORS_HPP
#define FALK_OPERATORS_HPP

namespace falk {
    namespace op {
        enum class Arithmetical {
            ADD,
            SUB,
            DIV,
            MULT,
            POW,
            MOD,
            ADD_ASSIGN,
            SUB_ASSIGN,
            DIV_ASSIGN,
            MULT_ASSIGN,
            POW_ASSIGN,
            MOD_ASSIGN,
        };

        enum class Comparison {
            LT,
            GT,
            LE,
            GE,
            EQ,
            NE,
        };

        enum class Logical {
            AND,
            OR,
            NOT,
            AND_ASSIGN,
            OR_ASSIGN,
        };
    }
}

#endif /* FALK_OPERATORS_HPP */
