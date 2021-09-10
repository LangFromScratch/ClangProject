#include "proc.h"

namespace clg {

    Value::Value()
    {
        m_type = ValueType::voidVal;
        intV = 0;
    }

    Value::Value(bool b)
    {
        m_type = ValueType::boolVal;
        boolV = b;
    }

    Value::Value(int i)
    {
        m_type = ValueType::intVal;
        intV = i;
    }

    Value::Value(double d)
    {
        m_type = ValueType::doubleVal;
        doubleV = d;
    }


    Value::Value(const Value& other)
    {
        *this = other;
    }

    Value& Value::operator=(const Value& other) {
        if (this != &other) {
            *this = other;
        }
        return *this;
    }
}
//end namespace ore