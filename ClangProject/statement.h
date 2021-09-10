#pragma once

namespace clg {

    //--------------------------------------------------------------------------------------
    ///  ���N���X
    //--------------------------------------------------------------------------------------
    class Statement : public ObjBase {
    protected:
        Statement() {}
    public:
        virtual ~Statement() {}
        //void�̎��s�֐�
        virtual Value execute() {
            return Value();
        }
    };

    //--------------------------------------------------------------------------------------
    ///  Dump���N���X
    //--------------------------------------------------------------------------------------
    class DumpStm : public Statement {
        Expression* m_expression;
    public:
        DumpStm(Expression* exp) :
            m_expression(exp)
        {}
        //���s�֐�
        virtual Value execute() override;
        virtual ~DumpStm() {}
    };

    //--------------------------------------------------------------------------------------
    ///  �����N���X
    //--------------------------------------------------------------------------------------
    class ExpressionStm : public Statement {
        Expression* m_expression;
    public:
        ExpressionStm(Expression* exp) :
            m_expression(exp)
        {}
        //���s�֐�
        virtual Value execute() override;
        virtual ~ExpressionStm() {}
    };




    //--------------------------------------------------------------------------------------
    ///  �����X�g�N���X
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
    ///  Compound�X�e�[�g�����g
    //--------------------------------------------------------------------------------------
    class CompoundStatement : public Statement {
        StatementList* m_pStatementList;
    public:
        CompoundStatement(StatementList* stml) :
            m_pStatementList(stml)
        {}
        virtual ~CompoundStatement() {}
        //���s�֐�
        virtual Value execute() override;
    };


}
//end namespace clg