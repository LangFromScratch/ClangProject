#include "proc.h"

namespace clg {

    void IntFunctionDeclaration::excute() {
        if (m_pCompoundStatement) {
            m_pCompoundStatement->execute();
        }
    }

}
//end namespace clg