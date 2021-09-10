#pragma once

namespace clg {


    //--------------------------------------------------------------------------------------
    ///  パラメータリストクラス
    //--------------------------------------------------------------------------------------
    class ParameterList : public ObjBase {
        const char* m_pIdent;
        ParameterList* m_Next;
    public:
        ParameterList() :
            m_pIdent(nullptr),
            m_Next(nullptr)
        {

        }
        ParameterList(const char* ident) :
            m_pIdent(ident),
            m_Next(nullptr)
        {

        }
        virtual ~ParameterList() {}
        const char* getIdent() const {
            return m_pIdent;
        }
        ParameterList* getNext()const {
            return m_Next;
        }
        void setNext(ParameterList* next) {
            m_Next = next;
        }
    };

    //--------------------------------------------------------------------------------------
    ///  宣言クラス
    //--------------------------------------------------------------------------------------
    class Declaration : public ObjBase {
    protected:
        Declaration() {}
    public:
        virtual ~Declaration() {}
    };


    //--------------------------------------------------------------------------------------
    ///  int型関数定義
    //--------------------------------------------------------------------------------------
    class IntFunctionDeclaration : public Declaration {
        const char* m_pIdent;
        CompoundStatement* m_pCompoundStatement;
    public:
        IntFunctionDeclaration(IdentifierExp* pIdent, Statement* stm) :
            m_pIdent{ pIdent->getIdentity() }
        {
            m_pCompoundStatement = dynamic_cast<CompoundStatement*>(stm);
        }
        const char* getIdentity() const {
            return m_pIdent;
        }
        void excute();
        virtual ~IntFunctionDeclaration() {}
    };



    //--------------------------------------------------------------------------------------
    ///  宣言リストクラス
    //--------------------------------------------------------------------------------------
    class DeclarationList : public ObjBase {
        Declaration* m_Declaration;
        DeclarationList* m_Next;
    public:
        DeclarationList(Declaration* decl) :
            m_Declaration(decl),
            m_Next(nullptr)
        {

        }
        Declaration* getDecl() const {
            return m_Declaration;

        }
        DeclarationList* getNext()const {
            return m_Next;
        }
        void setNext(DeclarationList* next) {
            m_Next = next;
        }
        virtual ~DeclarationList() {}
    };

}
// end namespace clg