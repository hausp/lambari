
#ifndef FALK_DEFINITIONS_HPP
#define FALK_DEFINITIONS_HPP

#include "interpreter/complex.hpp"

namespace falk {
    using real = double;
    using complex = complex_t;

    enum class Types {
        UNDEFINED,
        REAL,
        COMPLEX,
    }

    namespace operators {
        enum class Arithmetical {
            ADD,
            SUB,
            DIV,
            MULT,
            POWER,
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
        };
    }
}

#endif /* FALK_DEFINITIONS_HPP */
