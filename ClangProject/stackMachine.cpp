#include "proc.h"

namespace clg
{

    Value Root::execute() {
        //  main�֐���T���Ď��s
        FunctionCallExp* pFunc = new FunctionCallExp("main");
        pFunc->execute();
        return Value();
    }

    //�B��̃X�^�b�N�}�V���̃C���X�^���X
    StackMachine* g_pSackMachine;

    StackMachine::StackMachine()
    {}
    StackMachine::~StackMachine() {
        for (size_t i = 0; i < m_objPool.size(); i++) {
            delete m_objPool[i];
        }
        m_objPool.clear();
    }

    const char* StackMachine::createFixedString(const char* ext) {
        //255�����ɐ؂�l�߂�B
        auto str = clampToken(ext);
        auto it = m_fixedStringPool.insert(str);
        return it.first->c_str();
    }

    int StackMachine::compile(FILE* fp) {
        m_pRoot = new Root();
        extern int yyparse(void);
        extern FILE* yyin;
        yyin = fp;
        if (yyparse()) {
            return 1;
        }
        return 0;

    }
    void StackMachine::execute() {
        if (m_pRoot) {
            m_pRoot->execute();
        }
    }

    void StackMachine::destroy() {
        if (g_pSackMachine) {
            delete g_pSackMachine;
            g_pSackMachine = nullptr;
        }
    }

    //�C���X�^���X�Q��
    StackMachine* StackMachine::get() {
        if (!g_pSackMachine) {
            g_pSackMachine = new StackMachine();
        }
        return g_pSackMachine;
    }

    /// INT���e����
    Expression* StackMachine::createIntLiteralExp(const char* ptr) {
        string str = clampToken(ptr);
        auto pObj = new IntLiteralExp(std::stoi(str));
        m_objPool.push_back(pObj);
        return pObj;
    }

    Expression* StackMachine::createIdentifierExp(const char* ptr) {
        auto pStr = createFixedString(ptr);
        auto pObj = new IdentifierExp(pStr);
        m_objPool.push_back(pObj);
        return pObj;
    }

    //�֐��Ăяo��
    Expression* StackMachine::createFunctionCallExp(Expression* pIdent) {
        auto tgt = dynamic_cast<IdentifierExp*>(pIdent);
        if (tgt) {
            auto pObj = new FunctionCallExp(tgt->getIdentity());
            m_objPool.push_back(pObj);
            return pObj;
        }
        else {
            cout << "�֐��Ăяo�����Ԉ���Ă��܂�" << endl;
            exit(1);
        }
        return nullptr;
    }




    //�o��
    Statement* StackMachine::createDumpStm(Expression* exp) {
        auto pObj = new DumpStm(exp);
        m_objPool.push_back(pObj);
        return pObj;
    }

    Statement* StackMachine::createExpressionStm(Expression* exp) {
        auto pObj = new ExpressionStm(exp);
        m_objPool.push_back(pObj);
        return pObj;

    }


    //Compound��
    Statement* StackMachine::createCompoundStatement(StatementList* stml) {
        auto pObj = new CompoundStatement(stml);
        m_objPool.push_back(pObj);
        return pObj;

    }



    StatementList* StackMachine::createStatementList(Statement* stm) {
        auto pObj = new StatementList(stm);
        m_objPool.push_back(pObj);
        return pObj;
    }

    StatementList* StackMachine::createStatementList(StatementList* stml, Statement* stm) {
        StatementList* pos;
        if (stml == nullptr)
            return createStatementList(stm);
        for (pos = stml; pos->getNext(); pos = pos->getNext())
            ;
        pos->setNext(createStatementList(stm));
        return stml;
    }

    //�p�����[�^���X�g
    ParameterList* StackMachine::createParameterList() {
        auto ptr = new ParameterList();
        m_objPool.push_back(ptr);
        return ptr;
    }

    //�錾

    //int�^�֐���`
    Declaration* StackMachine::createIntFunctionDeclaration(Expression* pExp, Statement* stm) {
        IdentifierExp* pIdent = dynamic_cast<IdentifierExp*>(pExp);
        CompoundStatement* pComp = dynamic_cast<CompoundStatement*>(stm);
        if (pIdent && stm) {
            auto pObj = new IntFunctionDeclaration(pIdent, stm);
            m_objPool.push_back(pObj);
            return pObj;
        }
        else {
            cout << "�֐���`���Ԉ���Ă��܂�" << endl;
            exit(1);
        }
        return nullptr;
    }



    DeclarationList* StackMachine::createDeclarationList(Declaration* decl) {
        auto pObj = new DeclarationList(decl);
        m_objPool.push_back(pObj);
        return pObj;
    }
    DeclarationList* StackMachine::createDeclarationList(DeclarationList* declList, Declaration* decl) {
        DeclarationList* pos;
        if (declList == nullptr)
            return createDeclarationList(decl);
        for (pos = declList; pos->getNext(); pos = pos->getNext())
            ;
        pos->setNext(createDeclarationList(decl));
        return declList;
    }

    //���[�g�ւ�DeclarationList�̒ǉ�
    Root* StackMachine::addRootDeclarationList(DeclarationList* decl) {
        if (m_pRoot) {
            m_pRoot->setDeclList(decl);
        }
        return m_pRoot;
    }


}
//end namespace clg