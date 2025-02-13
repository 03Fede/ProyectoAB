#ifndef IMEDICOFUNCIONES_H
#define IMEDICOFUNCIONES_H

#include <string>

class IMedicoFunciones {
public:
    virtual void prescribirMedicamento(const std::string& medicamento) = 0;
    virtual ~IMedicoFunciones() = default;
};

#endif