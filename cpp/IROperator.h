#ifndef IR_OPERATOR_H
#define IR_OPERATOR_H

#include "IR.h"

namespace Halide {

inline Expr operator+(Expr a, Expr b) {
    return new Add(a, b);
}
    
inline Expr &operator+=(Expr &a, Expr b) {
    a = new Add(a, b);
    return a;
}

inline Expr operator-(Expr a, Expr b) {
    return new Sub(a, b);
}
    
inline Expr &operator-=(Expr &a, Expr b) {
    a = new Sub(a, b);
    return a;
}

inline Expr operator*(Expr a, Expr b) {
    return new Mul(a, b);
}
    
inline Expr &operator*=(Expr &a, Expr b) {
    a = new Mul(a, b);
    return a;
}

inline Expr operator/(Expr a, Expr b) {
    return new Div(a, b);
}

inline Expr &operator/=(Expr &a, Expr b) {
    a = new Div(a, b);
    return a;
}

inline Expr operator%(Expr a, Expr b) {
    return new Mod(a, b);
}

inline Expr operator>(Expr a, Expr b) {
    return new GT(a, b);
}

inline Expr operator<(Expr a, Expr b) {
    return new LT(a, b);
}

inline Expr operator<=(Expr a, Expr b) {
    return new LE(a, b);
}

inline Expr operator>=(Expr a, Expr b) {
    return new GE(a, b);
}

inline Expr operator==(Expr a, Expr b) {
    return new EQ(a, b);
}

inline Expr operator!=(Expr a, Expr b) {
    return new NE(a, b);
}

inline Expr operator&&(Expr a, Expr b) {
    return new And(a, b);
}

inline Expr operator||(Expr a, Expr b) {
    return new Or(a, b);
}

inline Expr operator!(Expr a) {
    return new Not(a);
}

inline Expr max(Expr a, Expr b) {
    return new Max(a, b);
}

inline Expr min(Expr a, Expr b) {
    return new Min(a, b);
}

inline Expr clamp(Expr a, Expr min_val, Expr max_val) {
    return new Max(new Min(a, max_val), min_val);
}

template<typename T>
inline Expr cast(Expr a) {
    return new Cast(type_of<T>(), a);
}

inline Expr cast(Type t, Expr a) {
    return new Cast(t, a);
}

inline Expr select(Expr a, Expr b, Expr c) {
    return new Select(a, b, c);
}

namespace Internal {
bool is_const(Expr e);
bool is_positive_const(Expr e);
bool is_negative_const(Expr e);
bool is_zero(Expr e);
bool is_one(Expr e);
Expr make_zero(Type t);
Expr make_one(Type t);
Expr const_true(int width = 1);
Expr const_false(int width = 1);
}

}


#endif
