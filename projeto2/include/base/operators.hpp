
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
        };
    }
}

#endif /* FALK_OPERATORS_HPP */
