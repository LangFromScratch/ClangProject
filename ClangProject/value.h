#pragma once

namespace clg {

    //--------------------------------------------------------------------------------------
    ///  値タイプ
    //--------------------------------------------------------------------------------------
    enum class ValueType {
        voidVal = 0,
        boolVal,
        intVal,
        doubleVal,
    };


    //--------------------------------------------------------------------------------------
    ///  値
    //--------------------------------------------------------------------------------------
    struct Value {
        ValueType m_type;
        union {
            bool boolV;
            int intV;
            double doubleV;
        };
        explicit Value();
        explicit Value(bool b);
        explicit Value(int i);
        explicit Value(double d);
        Value(const Value& other);
        Value& operator=(const Value& other);
        ~Value() {}
    };



}
// end namespace clg