#pragma once

namespace clg {

#define ORE_MAX_TOKEN_LEN 255

    ///string��255�����ɐ؂�l�߂�
    inline string clampToken(const char* ext) {
        string str(ext);
        if (str.size() > ORE_MAX_TOKEN_LEN) {
            str.erase(ORE_MAX_TOKEN_LEN);
        }
        return str;
    }

    //--------------------------------------------------------------------------------------
    ///  Object�x�[�X�i���N���X�j
    //--------------------------------------------------------------------------------------
    class ObjBase {
    protected:
        ObjBase() {}
    public:
        virtual ~ObjBase() {}
    };

}
//end namespace clg