/*--
  Entage

	Copyrighted material. See LICENSE.txt for more information.
--*/

#ifndef _ENTAGE_ARRAY_SIMPLE_
#define _ENTAGE_ARRAY_SIMPLE_

#include "TreeElement.h"
#include "Types.h"
#include <vector>

namespace Entage
{
	template<typename T> class TreeArray : public TreeElement, public std::vector<T>
	{
	public:
		TreeArray(const std::string& _element_name) :
			TreeElement(get_value_type< TreeArray<T> >()),
			element_name(_element_name)
		{
		}

	protected:
		std::string element_name;
	};
}

#endif