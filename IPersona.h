#ifndef IPERSONA_H
#define IPERSONA_H

#include "IGestionable.h"
#include <string>   


class IPersona : public IGestionable {
public:
    virtual std::string getNombre() const = 0;
    virtual ~IPersona() = default;
};

#endif