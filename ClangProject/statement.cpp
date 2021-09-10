#include "proc.h"

namespace clg
{

    //--------------------------------------------------------------------------------------
    ///  Dump文クラス
    //--------------------------------------------------------------------------------------
    Value DumpStm::execute() {
        if (m_expression) {
            auto val = m_expression->execute();
            switch (val.m_type) {
            case ValueType::intVal:
                cout << val.intV << endl;
                break;
            }
        }
        return Value();
    }

    //--------------------------------------------------------------------------------------
    ///  式文クラス
    //--------------------------------------------------------------------------------------
    Value ExpressionStm::execute() {
        if (m_expression) {
            auto val = m_expression->execute();
        }
        return Value();
    }


    void StatementList::execute() {
        auto pos = this;
        do {
            auto stm = pos->getStm();
            stm->execute();
            pos = pos->getNext();
        } while (pos);

    }

    Value CompoundStatement::execute() {
        if (m_pStatementList) {
            m_pStatementList->execute();
        }
        return Value();
    }



}
// end namespace clg