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
// Created by softboy on 7/25/17.

#ifndef ZAPI_BRIDGE_INIENTRY_H
#define ZAPI_BRIDGE_INIENTRY_H

#include "zapi/Global.h"
#include <string>

struct _zend_ini_entry;

namespace zapi
{
namespace bridge
{

class IniEntryPrivate;

class ZAPI_DECL_EXPORT IniEntry
{
public:
   enum class CfgType : int
   {
      User    = ZEND_INI_USER,
      PerDir  = ZEND_INI_PERDIR,
      System  = ZEND_INI_SYSTEM,
      All     = ZEND_INI_USER | ZEND_INI_PERDIR | ZEND_INI_SYSTEM
   };
   
public:
   IniEntry(const char *name, const char *value, const CfgType cfgType = CfgType::All);
   IniEntry(const char *name, bool value, const CfgType cfgType = CfgType::All);
   IniEntry(const char *name, const int16_t value, const CfgType cfgType = CfgType::All);
   IniEntry(const char *name, const int32_t value, const CfgType cfgType = CfgType::All);
   IniEntry(const char *name, const int64_t value, const CfgType cfgType = CfgType::All);
   IniEntry(const char *name, const double value, const CfgType cfgType = CfgType::All);
   IniEntry(const IniEntry &other);
   IniEntry(IniEntry &&other);
   ~IniEntry();
   
public:
   bool operator==(const IniEntry &other) const;
   void setupIniEntryDef(struct _zend_ini_entry_def *zendIniDef, int moduleNumber = -1);
   
private:
   ZAPI_DECLARE_PRIVATE(IniEntry)
   std::unique_ptr<IniEntryPrivate> m_implPtr;
};


class IniValuePrivate;

/**
 * @brief Class IniValue designed for extracting values from ini entries.
 */
class ZAPI_DECL_EXPORT IniValue
{
public:
   IniValue(const char *name, const bool isOrig);
   IniValue(const IniValue &value);
   IniValue(IniValue &&value);
   ~IniValue();
public:
   
   int64_t getNumericValue() const;
   const char *getRawValue() const;
   bool getBoolValue() const;
   std::string getStringValue() const;
   
   /**
    * Cast to a floating point
    * 
    * @return double
    */
   operator double () const;
   
   operator int16_t () const
   {
      return static_cast<int16_t>(getNumericValue());
   }
   
   operator int32_t () const 
   {
      return static_cast<int32_t>(getNumericValue());
   }
   
   operator int64_t () const
   {
      return getNumericValue();
   }
   
   operator bool () const
   {
      return getBoolValue();
   }
   
   operator std::string () const
   {
      return getStringValue();
   }
   
   operator const char * () const
   {
      return getRawValue();
   }
   
private:
   ZAPI_DECLARE_PRIVATE(IniValue)
   std::unique_ptr<IniValuePrivate> m_implPtr;
};

ZAPI_DECL_EXPORT std::ostream &operator<<(std::ostream &stream, const IniValue &iniValue);

} // kernel
} // zapi

#endif // ZAPI_BRIDGE_INIENTRY_H