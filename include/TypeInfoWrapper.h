#pragma once

#include <typeinfo>

class TypeInfoWrapper
{
private:
    const std::type_info &info_;
public:
    TypeInfoWrapper(const std::type_info &info): info_(info)
    {
    }
};
