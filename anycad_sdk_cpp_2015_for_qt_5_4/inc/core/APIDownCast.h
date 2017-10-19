#pragma once

#include <memory>

namespace AnyCAD{ namespace API{

    template<class TSubClass, class TBaseClass>
    inline std::unique_ptr<TSubClass> DownCast(const TBaseClass& obj)
    {
        return std::unique_ptr<TSubClass>(dynamic_cast<TSubClass*>(_DownCastImpl(obj)));
    }

   class Object;
   AnyPlatformAPI_API Object* _DownCastImpl(const Object& obj);

}}
