// Copyright 2017-2018 zzu_softboy <zzu_softboy@163.com>
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Created by zzu_softboy on 2017/08/01.

#include "zapi/lang/Method.h"
#include "zapi/vm/internal/CallablePrivate.h"

namespace zapi
{
namespace lang
{

namespace internal
{

using zapi::vm::internal::CallablePrivate;
using zapi::lang::Modifier;

class MethodPrivate : public CallablePrivate
{
public:
   MethodPrivate(const char *name, MethodCallable0 callback, Modifier flags, const Arguments &args)
      : CallablePrivate(name, args),
        m_type(0),
        m_flags(flags)
   {
      m_callable.methodCallback0 = callback;
   }
   
   MethodPrivate(const char *name, MethodCallable1 callback, Modifier flags, const Arguments &args)
      : CallablePrivate(name, args),
        m_type(1),
        m_flags(flags)
   {
      m_callable.methodCallback1 = callback;
   }
   
   MethodPrivate(const char *name, MethodCallable2 callback, Modifier flags, const Arguments &args)
      : CallablePrivate(name, args),
        m_type(2),
        m_flags(flags)
   {
      m_callable.methodCallback2 = callback;
   }
   
   MethodPrivate(const char *name, MethodCallable3 callback, Modifier flags, const Arguments &args)
      : CallablePrivate(name, args),
        m_type(3),
        m_flags(flags)
   {
      m_callable.methodCallback3 = callback;
   }
   
   MethodPrivate(const char *name, MethodCallable4 callback, Modifier flags, const Arguments &args)
      : CallablePrivate(name, args),
        m_type(4),
        m_flags(flags)
   {
      m_callable.methodCallback4 = callback;
   }
   
   MethodPrivate(const char *name, MethodCallable5 callback, Modifier flags, const Arguments &args)
      : CallablePrivate(name, args),
        m_type(5),
        m_flags(flags)
   {
      m_callable.methodCallback5 = callback;
   }
   
   MethodPrivate(const char *name, MethodCallable6 callback, Modifier flags, const Arguments &args)
      : CallablePrivate(name, args),
        m_type(6),
        m_flags(flags)
   {
      m_callable.methodCallback6 = callback;
   }
   
   MethodPrivate(const char *name, MethodCallable7 callback, Modifier flags, const Arguments &args)
      : CallablePrivate(name, args),
        m_type(7),
        m_flags(flags)
   {
      m_callable.methodCallback7 = callback;
   }
   
   MethodPrivate(const char *name, MethodCallable8 callback, Modifier flags, const Arguments &args)
      : CallablePrivate(name, args),
        m_type(8),
        m_flags(flags)
   {
      m_callable.methodCallback8 = callback;
   }
   
   MethodPrivate(const char *name, MethodCallable9 callback, Modifier flags, const Arguments &args)
      : CallablePrivate(name, args),
        m_type(9),
        m_flags(flags)
   {
      m_callable.methodCallback9 = callback;
   }
   
   MethodPrivate(const char *name, MethodCallable10 callback, Modifier flags, const Arguments &args)
      : CallablePrivate(name, args),
        m_type(10),
        m_flags(flags)
   {
      m_callable.methodCallback10 = callback;
   }
   
   MethodPrivate(const char *name, MethodCallable11 callback, Modifier flags, const Arguments &args)
      : CallablePrivate(name, args),
        m_type(11),
        m_flags(flags)
   {
      m_callable.methodCallback11 = callback;
   }
   
   MethodPrivate(const char *name, Modifier flags, const Arguments &args)
      : CallablePrivate(name, args),
        m_type(-1),
        m_flags(flags)
   {
      m_callable.methodCallback0 = nullptr;
   }
   
   MethodPrivate(const MethodPrivate &other)
      : CallablePrivate(other),
        m_type(other.m_type),
        m_flags(other.m_flags)
   {
   }
   
   MethodPrivate(MethodPrivate &&other) ZAPI_DECL_NOEXCEPT
      : CallablePrivate(std::move(other)),
        m_type(other.m_type),
        m_flags(other.m_flags)
   {}
   
   MethodPrivate &operator=(const MethodPrivate &other)
   {
      CallablePrivate::operator=(other);
      m_type = other.m_type;
      m_flags = other.m_flags;
      return *this;
   }
   
   MethodPrivate &operator=(MethodPrivate &&other) ZAPI_DECL_NOEXCEPT
   {
      CallablePrivate::operator=(std::move(other));
      m_type = other.m_type;
      m_flags = other.m_flags;
      return *this;
   }
   
   void initialize(zend_function_entry *entry, const std::string &className);
   int m_type;
   Modifier m_flags;
   union {
      zapi::MethodCallable0 methodCallback0;
      zapi::MethodCallable1 methodCallback1;
      zapi::MethodCallable2 methodCallback2;
      zapi::MethodCallable3 methodCallback3;
      zapi::MethodCallable4 methodCallback4;
      zapi::MethodCallable5 methodCallback5;
      zapi::MethodCallable6 methodCallback6;
      zapi::MethodCallable7 methodCallback7;
      // add native signature
      zapi::NativeCallable0 methodCallback8;
      zapi::NativeCallable1 methodCallback9;
      zapi::NativeCallable2 methodCallback10;
      zapi::NativeCallable3 methodCallback11;
   } m_callable;
};

void MethodPrivate::initialize(zend_function_entry *entry, const std::string &className)
{
   if ((m_flags & (Modifier::Public | Modifier::Private | Modifier::Protected)) == 0) {
      m_flags |= Modifier::Public;
   }
   CallablePrivate::initialize(entry, className.c_str(), static_cast<int>(m_flags));
}

} // internal

using internal::MethodPrivate;

Method::Method(const char *name, MethodCallable0 callback, Modifier flags, const Arguments &args)
   : Callable(new MethodPrivate(name, callback, flags, args))
{}

Method::Method(const char *name, MethodCallable1 callback, Modifier flags, const Arguments &args)
   : Callable(new MethodPrivate(name, callback, flags, args))
{}

Method::Method(const char *name, MethodCallable2 callback, Modifier flags, const Arguments &args)
   : Callable(new MethodPrivate(name, callback, flags, args))
{}

Method::Method(const char *name, MethodCallable3 callback, Modifier flags, const Arguments &args)
   : Callable(new MethodPrivate(name, callback, flags, args))
{}

Method::Method(const char *name, MethodCallable4 callback, Modifier flags, const Arguments &args)
   : Callable(new MethodPrivate(name, callback, flags, args))
{}

Method::Method(const char *name, MethodCallable5 callback, Modifier flags, const Arguments &args)
   : Callable(new MethodPrivate(name, callback, flags, args))
{}

Method::Method(const char *name, MethodCallable6 callback, Modifier flags, const Arguments &args)
   : Callable(new MethodPrivate(name, callback, flags, args))
{}

Method::Method(const char *name, MethodCallable7 callback, Modifier flags, const Arguments &args)
   : Callable(new MethodPrivate(name, callback, flags, args))
{}

Method::Method(const char *name, MethodCallable8 callback, Modifier flags, const Arguments &args)
   : Callable(new MethodPrivate(name, callback, flags, args))
{}

Method::Method(const char *name, MethodCallable9 callback, Modifier flags, const Arguments &args)
   : Callable(new MethodPrivate(name, callback, flags, args))
{}

Method::Method(const char *name, MethodCallable10 callback, Modifier flags, const Arguments &args)
   : Callable(new MethodPrivate(name, callback, flags, args))
{}

Method::Method(const char *name, MethodCallable11 callback, Modifier flags, const Arguments &args)
   : Callable(new MethodPrivate(name, callback, flags, args))
{}

Method::Method(const char *name, Modifier flags, const Arguments &args)
   : Callable(new MethodPrivate(name, flags, args))
{}

Method::Method(const Method &other)
{
   ZAPI_D(Method);
   m_implPtr.reset(new MethodPrivate(*implPtr));
}

Method &Method::operator=(const Method &other)
{
   ZAPI_D(Method);
   m_implPtr.reset(new MethodPrivate(*implPtr));
   return *this;
}

Method::~Method()
{}

Variant Method::invoke(Parameters &parameters)
{
   
}

void Method::initialize(zend_function_entry *entry, const char *className)
{
   ZAPI_D(Method);
   implPtr->initialize(entry, className);
}

} // lang
} // zapi