/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2013 Facebook, Inc. (http://www.facebook.com)     |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/
#include "hphp/hhbbc/unit-util.h"

#include "hphp/hhbbc/representation.h"
#include "hphp/runtime/base/static-string-table.h"

namespace HPHP { namespace HHBBC {

//////////////////////////////////////////////////////////////////////

bool is_systemlib_part(const php::Unit& unit) {
  static const char prefix[] = "/:systemlib";
  return !*unit.filename->data() ||
    !strncmp(unit.filename->data(), prefix, sizeof prefix - 1);
}

bool isNSNormalized(SString name) {
  return name->data()[0] != '\\';
}

SString normalizeNS(SString name) {
  if (name->data()[0] == '\\' && name->data()[1] != '\\') {
    return makeStaticString(StringSlice(name->data() + 1, name->size() - 1));
  }
  return name;
}

//////////////////////////////////////////////////////////////////////

}}

