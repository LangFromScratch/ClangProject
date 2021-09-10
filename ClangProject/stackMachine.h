#pragma once

namespace clg
{

    //--------------------------------------------------------------------------------------
    ///  ���[�g�N���X
    //--------------------------------------------------------------------------------------
    class Root : public ObjBase {
        DeclarationList* m_pDeclarationList;
    public:
        Root() :
            m_pDeclarationList(nullptr)
        {}
        virtual ~Root() {}
        Value execute();
        void setDeclList(DeclarationList* decl) {
            m_pDeclarationList = decl;
        }
        DeclarationList* getDeclList()const {
            return m_pDeclarationList;
        }
    };

    //--------------------------------------------------------------------------------------
    ///  �X�^�b�N�}�V���N���X
    //--------------------------------------------------------------------------------------
    class StackMachine {
        //���߃|�C���^
        unsigned int m_ip = 0;
        //���[�g�I�u�W�F�N�g
        Root* m_pRoot;
        //�I�u�W�F�N�g�̃v�[��
        vector<ObjBase*> m_objPool;
        //������̃v�[��
        set<string> m_fixedStringPool;
        const char* createFixedString(const char* ext);
        StackMachine();
    public:
        virtual ~StackMachine();
        int compile(FILE* fp);
        void execute();
        void destroy();
        //�C���X�^���X�Q��
        static StackMachine* get();
        Root* getRoot() {
            return m_pRoot;
        }
        //��
        /// INT���e����
        Expression* createIntLiteralExp(const char* ptr);
        //���ʎq
        Expression* createIdentifierExp(const char* ptr);
        //�֐��Ăяo��
        Expression* createFunctionCallExp(Expression* pIdent);
        //��
        //�f�o�b�O�o��
        Statement* createDumpStm(Expression* exp);
        //����
        Statement* createExpressionStm(Expression* exp);
        //Compound��
        Statement* createCompoundStatement(StatementList* stml = nullptr);
        //�����X�g
        StatementList* createStatementList(Statement* stm);
        StatementList* createStatementList(StatementList* stml, Statement* stm);
        //�p�����[�^���X�g
        ParameterList* createParameterList();
        //�錾
        //int�^�֐���`
        Declaration* createIntFunctionDeclaration(Expression* pExp, Statement* stm);

        //�錾���X�g
        DeclarationList* createDeclarationList(Declaration* decl);
        DeclarationList* createDeclarationList(DeclarationList* declList, Declaration* decl);

        //���[�g�ւ�DeclarationList�̒ǉ�
        Root* addRootDeclarationList(DeclarationList* decl);

    };
}
//end namespace clg