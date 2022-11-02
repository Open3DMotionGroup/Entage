/*--
  Entage

	Copyrighted material. See LICENSE.txt for more information.
--*/

#ifndef _ENTAGE_MAP_H_
#define _ENTAGE_MAP_H_

#include "MapBase.h"
#include "Entage/Tree/TreeValue.h"

namespace Entage
{
	template<class T> class MapValue : public MapBase< TreeValue<T> >
	{
	public:
		static const T default_value;

	public:
		MapValue(ViewCompound* _container, const std::string& _name) :
			MapBase< TreeValue<T> >(_container, _name)
		{
		}

		const T& value() const
		{
			const TreeValue<T>* result = MapBase< TreeValue<T> >::lookup();
			return (result != nullptr) ? (const T&)*result : MapValue<T>::default_value;
		}

		T& value()
		{
			TreeValue<T>* result = MapBase< TreeValue<T> >::lookup();
			if (result == nullptr)
			{
				result = new TreeValue<T>(MapValue<T>::default_value);
				MapBase< TreeValue<T> >::set(result);
			}
			return *result;
		}

		operator explicit const T& () const
		{
			return value();
		}

		operator explicit T& ()
		{
			return value();
		}

	};

}

#endif