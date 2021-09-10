#pragma once

namespace clg {

    //--------------------------------------------------------------------------------------
    ///  ���N���X
    //--------------------------------------------------------------------------------------
    class Expression : public ObjBase {
    protected:
        Expression() {}
    public:
        virtual ~Expression() {}
        virtual Value execute() {
            return Value();
        }
    };

    //--------------------------------------------------------------------------------------
    ///  int���e�������N���X
    //--------------------------------------------------------------------------------------
    class IntLiteralExp : public Expression {
        int m_intValue;
    public:
        IntLiteralExp(int i = 0) {
            m_intValue = i;
        }
        virtual ~IntLiteralExp() {}
        virtual Value execute() override;
    };

    //--------------------------------------------------------------------------------------
    ///  ���ʎq���N���X
    //--------------------------------------------------------------------------------------
    class IdentifierExp : public Expression {
        const char* m_Identity;
    public:
        IdentifierExp(const char* ident) :
            m_Identity(ident)
        {
        }
        const char* getIdentity() const {
            return m_Identity;
        }
        virtual ~IdentifierExp() {}
        virtual Value execute() override;
    };

    //--------------------------------------------------------------------------------------
    ///  �֐��Ăяo�����N���X
    //--------------------------------------------------------------------------------------
    class FunctionCallExp : public Expression {
        const char* m_Identity;
    public:
        FunctionCallExp(const char* ident) :
            m_Identity(ident) {
        }
        const char* getIdentity() const {
            return m_Identity;
        }
        virtual ~FunctionCallExp() {}
        virtual Value execute() override;
    };


}
//end namespace clg