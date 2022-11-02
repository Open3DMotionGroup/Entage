/*--
  Entage

	Copyrighted material. See LICENSE.txt for more information.
--*/

#ifndef _ENTAGE_VALUE_SIMPLE_H_
#define _ENTAGE_VALUE_SIMPLE_H_

#include "TreeElement.h"
#include "Types.h"

namespace Entage
{
	template<class T> class TreeValue : public TreeElement
	{
	public:
		TreeValue(const T& x) :
			TreeElement(get_value_type< TreeValue<T> >()),
			content(x)
		{
		}

		operator explicit const T& () const
		{
			return content;
		}

		operator explicit T& ()
		{
			return content;
		}

	private:
		T content;
	};
}

#endif