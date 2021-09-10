#pragma once

namespace clg {

#define ORE_MAX_TOKEN_LEN 255

    ///stringを255文字に切り詰める
    inline string clampToken(const char* ext) {
        string str(ext);
        if (str.size() > ORE_MAX_TOKEN_LEN) {
            str.erase(ORE_MAX_TOKEN_LEN);
        }
        return str;
    }

    //--------------------------------------------------------------------------------------
    ///  Objectベース（基底クラス）
    //--------------------------------------------------------------------------------------
    class ObjBase {
    protected:
        ObjBase() {}
    public:
        virtual ~ObjBase() {}
    };

}
//end namespace clg