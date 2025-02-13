#ifndef IGESTIONABLE_H
#define IGESTIONABLE_H

class IGestionable {
public:
    virtual void mostrarInformacion() const = 0;
    virtual int getId() const = 0;
    virtual ~IGestionable() {}
};

#endif
