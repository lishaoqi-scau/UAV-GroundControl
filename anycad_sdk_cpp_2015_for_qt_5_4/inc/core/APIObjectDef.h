#ifndef APIObject_h__
#define APIObject_h__

#include "inc/APIClassPtrDef.h"

namespace AnyCAD { namespace API
{

#define DECLARE_APIOBJECT(className)\
public:\
   typedef AnyCore::A##className##Ptr ObjectPtr;\
   className();\
   className(const className::ObjectPtr& implObject)\
   {\
   SetImpl(implObject);\
}\
   virtual ~className(){}\
   virtual bool IsNull() const { return className##Impl_ == 0; }\
   bool IsValid() const { return !IsNull(); }\
private:\
   ObjectPtr className##Impl_;\
public:\
   const ObjectPtr& GetImpl() const { return className##Impl_; }\
   void SetImpl(const ObjectPtr& impl) { className##Impl_ = impl; }

#define DECLARE_APISUPER(className, super)\
   typedef super Super;\
public:\
   typedef AnyCore::A##className##Ptr ObjectPtr;\
   className();\
   className(const className::ObjectPtr& implObject)\
   {\
   SetImpl(implObject);\
}\
   virtual ~className(){}\
   virtual bool IsNull() const { return className##Impl_ == 0; }\
   bool IsValid() const { return !IsNull(); }\
private:\
   ObjectPtr className##Impl_;\
public:\
   const ObjectPtr& GetImpl() const { return className##Impl_; }\
   void SetImpl(const ObjectPtr& impl);

#define IMPLEMENT_APISUPER(className)\
   void className::SetImpl(const ObjectPtr& impl) { Super::SetImpl(impl); className##Impl_ = impl; }
}}


#endif // APIObject_h__