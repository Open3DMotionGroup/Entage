/*--
  Entage

	Copyrighted material. See LICENSE.txt for more information.
--*/

#ifndef _ENTAGE_VALUE_H_
#define _ENTAGE_VALUE_H_

#include <cstdint>
#include <iostream>

namespace Entage
{
	class TreeElement
	{
	public:
		const int32_t instance_type;

	public:
		TreeElement(int32_t _instance_type)
			: instance_type(_instance_type)
		{
		}

		virtual ~TreeElement() { };

	};

	template<typename T> int32_t get_value_type() { return 0; }

	template<class T> T* TreeElementCast(TreeElement* value)
	{ return ((value != nullptr) && (value->instance_type == get_value_type<T>())) ? static_cast<T*> (value) : nullptr; }

	template<class T> const T* TreeElementCast(const TreeElement* value)
	{ return ((value != nullptr) && (value->instance_type == get_value_type<T>())) ? static_cast<const T*> (value) : nullptr; }

}

#endif
