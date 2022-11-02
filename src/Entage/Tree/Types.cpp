/*--
  Entage

	Copyrighted material. See LICENSE.txt for more information.
--*/

#include "Types.h"

namespace Entage
{
	template<> int32_t get_value_type<class TreeCompound>() { return value_type_compound; }
	template<> int32_t get_value_type<class TreeArrayCompound>() { return value_type_compound_array; }
	template<> int32_t get_value_type<class TreeValue<bool> >() { return value_type_bool; }
	template<> int32_t get_value_type<class TreeValue<int32_t> >() { return value_type_int32; }
	template<> int32_t get_value_type<class TreeValue<double> >() { return value_type_float64; }
	template<> int32_t get_value_type<class TreeValue<std::string> >() { return value_type_string; }
	template<> int32_t get_value_type<class TreeArray<bool> >() { return value_type_bool_array; }
	template<> int32_t get_value_type<class TreeArray<int32_t> >() { return value_type_int32_array; }
	template<> int32_t get_value_type<class TreeArray<double> >() { return value_type_float64_array; }
	template<> int32_t get_value_type<class TreeArray<std::string> >() { return value_type_string_array; }
}