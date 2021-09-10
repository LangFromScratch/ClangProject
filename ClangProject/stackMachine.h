#pragma once

namespace clg
{

    //--------------------------------------------------------------------------------------
    ///  ルートクラス
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
    ///  スタックマシンクラス
    //--------------------------------------------------------------------------------------
    class StackMachine {
        //命令ポインタ
        unsigned int m_ip = 0;
        //ルートオブジェクト
        Root* m_pRoot;
        //オブジェクトのプール
        vector<ObjBase*> m_objPool;
        //文字列のプール
        set<string> m_fixedStringPool;
        const char* createFixedString(const char* ext);
        StackMachine();
    public:
        virtual ~StackMachine();
        int compile(FILE* fp);
        void execute();
        void destroy();
        //インスタンス参照
        static StackMachine* get();
        Root* getRoot() {
            return m_pRoot;
        }
        //式
        /// INTリテラル
        Expression* createIntLiteralExp(const char* ptr);
        //識別子
        Expression* createIdentifierExp(const char* ptr);
        //関数呼び出し
        Expression* createFunctionCallExp(Expression* pIdent);
        //文
        //デバッグ出力
        Statement* createDumpStm(Expression* exp);
        //式文
        Statement* createExpressionStm(Expression* exp);
        //Compound文
        Statement* createCompoundStatement(StatementList* stml = nullptr);
        //文リスト
        StatementList* createStatementList(Statement* stm);
        StatementList* createStatementList(StatementList* stml, Statement* stm);
        //パラメータリスト
        ParameterList* createParameterList();
        //宣言
        //int型関数定義
        Declaration* createIntFunctionDeclaration(Expression* pExp, Statement* stm);

        //宣言リスト
        DeclarationList* createDeclarationList(Declaration* decl);
        DeclarationList* createDeclarationList(DeclarationList* declList, Declaration* decl);

        //ルートへのDeclarationListの追加
        Root* addRootDeclarationList(DeclarationList* decl);

    };
}
//end namespace clg