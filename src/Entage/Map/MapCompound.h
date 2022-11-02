/*--
  Entage

	Copyrighted material. See LICENSE.txt for more information.
--*/

#ifndef _ENTAGE_MAP_COMPOUND_H_
#define _ENTAGE_MAP_COMPOUND_H_

#include "MapBase.h"
#include "ViewCompound.h"
#include "Entage/Tree/TreeCompound.h"

namespace Entage
{
	extern const TreeCompound map_compound_empty;

	template<class CompoundViewT> class MapCompound : public MapBase<TreeCompound>, public CompoundViewT
	{
	public:
		MapCompound(ViewCompound* _container, const std::string& _name = "X") :
			MapBase<TreeCompound>(_container, _name)
		{
		}

		virtual TreeCompound* get_contents()
		{
			TreeCompound* contents = MapBase<TreeCompound>::lookup();

			if (contents == nullptr)
			{
				contents = new TreeCompound();
				MapBase<TreeCompound>::set(contents);
			}

			return contents;
		}

		virtual const TreeCompound* get_contents() const
		{
			const TreeCompound* contents = MapBase<TreeCompound>::lookup();

			if (contents == nullptr)
			{
				contents = &map_compound_empty;
			}

			return contents;
		}

	};

}

#endif