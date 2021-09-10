#pragma once

namespace clg {

    //--------------------------------------------------------------------------------------
    ///  文クラス
    //--------------------------------------------------------------------------------------
    class Statement : public ObjBase {
    protected:
        Statement() {}
    public:
        virtual ~Statement() {}
        //voidの実行関数
        virtual Value execute() {
            return Value();
        }
    };

    //--------------------------------------------------------------------------------------
    ///  Dump文クラス
    //--------------------------------------------------------------------------------------
    class DumpStm : public Statement {
        Expression* m_expression;
    public:
        DumpStm(Expression* exp) :
            m_expression(exp)
        {}
        //実行関数
        virtual Value execute() override;
        virtual ~DumpStm() {}
    };

    //--------------------------------------------------------------------------------------
    ///  式文クラス
    //--------------------------------------------------------------------------------------
    class ExpressionStm : public Statement {
        Expression* m_expression;
    public:
        ExpressionStm(Expression* exp) :
            m_expression(exp)
        {}
        //実行関数
        virtual Value execute() override;
        virtual ~ExpressionStm() {}
    };




    //--------------------------------------------------------------------------------------
    ///  文リストクラス
    //--------------------------------------------------------------------------------------
    class StatementList : public ObjBase {
        Statement* m_Statement;
        StatementList* m_Next;
    public:
        StatementList(Statement* stm) :
            m_Statement(stm),
            m_Next(nullptr)
        {

        }
        Statement* getStm() const {
            return m_Statement;

        }
        StatementList* getNext()const {
            return m_Next;
        }
        void setNext(StatementList* next) {
            m_Next = next;
        }
        void execute();
        virtual ~StatementList() {}
    };

    //--------------------------------------------------------------------------------------
    ///  Compoundステートメント
    //--------------------------------------------------------------------------------------
    class CompoundStatement : public Statement {
        StatementList* m_pStatementList;
    public:
        CompoundStatement(StatementList* stml) :
            m_pStatementList(stml)
        {}
        virtual ~CompoundStatement() {}
        //実行関数
        virtual Value execute() override;
    };


}
//end namespace clg