/*--
  Entage

	Copyrighted material. See LICENSE.txt for more information.
--*/

#include "MapValue.h"

namespace Entage
{
	const bool MapValue<bool>::default_value = false;
	const int32_t MapValue<int32_t>::default_value = 0;
	const double MapValue<double>::default_value = 0.0;
	const std::string MapValue<std::string>::default_value = std::string("");
}