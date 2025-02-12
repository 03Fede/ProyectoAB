#pragma once
#ifndef IGESTIONABLE_H
#define IGESTIONABLE_H

class IGestionable {
public:
    virtual int getId() const = 0;
    virtual ~IGestionable() {}
};

#endif
