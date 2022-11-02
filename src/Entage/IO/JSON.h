#ifndef _ENTAGE_JSON_H_
#define _ENTAGE_JSON_H_

#include <ostream>

#include "Entage/Tree/TreeElement.h"

namespace Entage
{
	void append_json(std::ostream& os, const TreeElement& v);
}

#endif