/*--
  Entage

	Copyrighted material. See LICENSE.txt for more information.
--*/

#ifndef _ENTAGE_VIEW_COMPOUND_H_
#define _ENTAGE_VIEW_COMPOUND_H_

#include "Entage/Tree/TreeCompound.h"

namespace Entage
{
	class ViewCompound
	{
	public:
		virtual ~ViewCompound()
		{
		}

		virtual TreeCompound* get_contents() = 0;

		virtual const TreeCompound* get_contents() const = 0;
	};
}

#define ENTAGE_MAP(Member) Member(this, #Member)

#define ENTAGE_MAP_ARRAY(Member, element_name) Member(this, #Member, element_name)

#endif