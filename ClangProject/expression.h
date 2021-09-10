#pragma once

namespace clg {

    //--------------------------------------------------------------------------------------
    ///  式クラス
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
    ///  intリテラル式クラス
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
    ///  識別子式クラス
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
    ///  関数呼び出し式クラス
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