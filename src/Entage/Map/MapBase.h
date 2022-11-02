/*--
  Entage

	Copyrighted material. See LICENSE.txt for more information.
--*/

#ifndef _ENTAGE_MAP_BASE_H_
#define _ENTAGE_MAP_BASE_H_

#include "ViewCompound.h"

namespace Entage
{
	template<class ValueT> class MapBase
	{
	public:
		MapBase(ViewCompound* _container, const std::string& _name) :
			container(_container),
			name(_name)
		{
		}

		bool is_set() const
		{
			return (lookup() != nullptr);
		}

		const ValueT* lookup() const
		{
			return container->get_contents()->get_type<ValueT>(name);
		}

		ValueT* lookup()
		{
			return container->get_contents()->get_type<ValueT>(name);
		}

		void set(ValueT* value)
		{
			container->get_contents()->set(name, value);
		}

	private:
		ViewCompound* container;
		const std::string name;
	};
}

#endif