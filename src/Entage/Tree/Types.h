/*--
  Entage

	Copyrighted material. See LICENSE.txt for more information.
--*/

#ifndef _ENTAGE_TYPES_H_
#define _ENTAGE_TYPES_H_

#include "TreeElement.h"

namespace Entage
{
	enum ValueType
	{
		value_type_undefined = 0,
		value_type_compound,
		value_type_compound_array,
		value_type_bool,
		value_type_bool_array,
		value_type_int32,
		value_type_int32_array,
		value_type_float64,
		value_type_float64_array,
		value_type_string,
		value_type_string_array,
	};

	template <class T> class TreeValue;
	template <class T> class TreeArray;
	class TreeCompound;
	class TreeArrayCompound;

	template<> int32_t get_value_type<class TreeCompound>();
	template<> int32_t get_value_type<class TreeArrayCompound>();
	template<> int32_t get_value_type<class TreeValue<bool> >();
	template<> int32_t get_value_type<class TreeValue<int32_t> >();
	template<> int32_t get_value_type<class TreeValue<double> >();
	template<> int32_t get_value_type<class TreeValue<std::string> >();
	template<> int32_t get_value_type<class TreeArray<bool> >();
	template<> int32_t get_value_type<class TreeArray<int32_t> >();
	template<> int32_t get_value_type<class TreeArray<double> >();
	template<> int32_t get_value_type<class TreeArray<std::string> >();
}

#endif