#pragma once

#include <memory>

template<typename ToClass, typename FromClass>
std::unique_ptr<ToClass> dynamic_unique_cast(std::unique_ptr<FromClass> &&from)
{
    if(ToClass *to = dynamic_cast<ToClass *>(from.get()))
    {
        std::unique_ptr<ToClass> result(to);
        from.release();
        return result;
    }
    return std::unique_ptr<ToClass>(nullptr);
}
