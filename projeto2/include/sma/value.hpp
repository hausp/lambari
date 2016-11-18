
#ifndef SMA_VALUE_HPP
#define SMA_VALUE_HPP

#include "ast/node.hpp"
#include "base/operators.hpp"

// Semantical Abstractions
namespace sma {
    // Abstraction for lvalues and rvalues.
    template<typename Analyser>
    class value {
        using node = ast::node<Analyser>;
        using node_ptr = std::unique_ptr<node>;
     public:
        template<typename T>
        value(T data):
          object{new ast::model<Analyser, T>{std::move(data)}} { }

        node* get_node() { return object.get(); }
    
        value<Analyser>& operator+=(value<Analyser>& rhs) {
            op_assign(rhs, Analyser::ADD_ASSIGN);
            return *this;
        }

        value<Analyser>& operator-=(value<Analyser>& rhs) {
            op_assign(rhs, Analyser::SUB_ASSIGN);
            return *this;
        }

        value<Analyser>& operator*=(value<Analyser>& rhs) {
            op_assign(rhs, Analyser::MULT_ASSIGN);
            return *this;
        }

        value<Analyser>& operator/=(value<Analyser>& rhs) {
            op_assign(rhs, Analyser::DIV_ASSIGN);
            return *this;
        }

        value<Analyser>& operator%=(value<Analyser>& rhs) {
            op_assign(rhs, Analyser::MOD_ASSIGN);
            return *this;
        }

        value<Analyser>& operator&=(value<Analyser>& rhs) {
            op_assign(rhs, Analyser::AND_ASSIGN);
            return *this;
        }

        value<Analyser>& operator|=(value<Analyser>& rhs) {
            op_assign(rhs, Analyser::OR_ASSIGN);
            return *this;
        }

        value<Analyser> operator!() {
            return op(*this, Analyser::NOT);
        }

        value<Analyser>& pow_assign(value<Analyser>& rhs) {
            op_assign(rhs, Analyser::POW_ASSIGN);
            return *this;
        }

        value<Analyser> pow(value<Analyser>& rhs) {
            return op(*this, rhs, Analyser::POW);
        }

     private:
        node_ptr object;

        template<typename T>
        void op_assign(value<Analyser>& rhs, const T& op) {
            auto n = std::make_unique<node>(op);
            n.add_subnode(std::move(object));
            n.add_subnode(std::move(rhs.object));
            object = n;
        }

        template<typename T>
        value<Analyser> op(value<Analyser>& lhs, value<Analyser>& rhs, const T& op) {
            auto n = std::make_unique<node>(op);
            n.add_subnode(std::move(object));
            n.add_subnode(std::move(rhs.object));
            return n;
        }

        template<typename T>
        value<Analyser> op(value<Analyser>& lhs, const T& op) {
            auto n = std::make_unique<node>(op);
            n.add_subnode(std::move(object));
            return n;
        }
    };

    template<typename Analyser>
    value<Analyser> operator+(value<Analyser>& lhs, value<Analyser>& rhs) {
        return op(lhs, rhs, Analyser::ADD);
    }

    template<typename Analyser>
    value<Analyser> operator-(value<Analyser>& lhs, value<Analyser>& rhs) {
        return op(lhs, rhs, Analyser::SUB);   
    }

    template<typename Analyser>
    value<Analyser> operator*(value<Analyser>& lhs, value<Analyser>& rhs) {
        return op(lhs, rhs, Analyser::MULT);
    }

    template<typename Analyser>
    value<Analyser> operator/(value<Analyser>& lhs, value<Analyser>& rhs) {
        return op(lhs, rhs, Analyser::DIV);
    }

    template<typename Analyser>
    value<Analyser> operator%(value<Analyser>& lhs, value<Analyser>& rhs) {
        return op(lhs, rhs, Analyser::MOD);
    }

    template<typename Analyser>
    value<Analyser> operator<(value<Analyser>& lhs, value<Analyser>& rhs) {
        return op(lhs, rhs, Analyser::LT);
    }

    template<typename Analyser>
    value<Analyser> operator>(value<Analyser>& lhs, value<Analyser>& rhs) {
        return op(lhs, rhs, Analyser::GT);
    }

    template<typename Analyser>
    value<Analyser> operator<=(value<Analyser>& lhs, value<Analyser>& rhs) {
        return op(lhs, rhs, Analyser::LE);
    }

    template<typename Analyser>
    value<Analyser> operator>=(value<Analyser>& lhs, value<Analyser>& rhs) {
        return op(lhs, rhs, Analyser::GE);
    }

    template<typename Analyser>
    value<Analyser> operator==(value<Analyser>& lhs, value<Analyser>& rhs) {
        return op(lhs, rhs, Analyser::EQ);
    }

    template<typename Analyser>
    value<Analyser> operator!=(value<Analyser>& lhs, value<Analyser>& rhs) {
        return op(lhs, rhs, Analyser::NE);
    }

    template<typename Analyser>
    value<Analyser> operator&&(value<Analyser>& lhs, value<Analyser>& rhs) {
        return op(lhs, rhs, Analyser::AND);
    }

    template<typename Analyser>
    value<Analyser> operator||(value<Analyser>& lhs, value<Analyser>& rhs) {
        return op(lhs, rhs, Analyser::OR);
    }
}

#endif /* SMA_VALUE_HPP */
