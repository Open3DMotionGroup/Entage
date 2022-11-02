/*--
  Entage

	Copyrighted material. See LICENSE.txt for more information.
--*/

#ifndef _ENTAGE_VIEW_COMPOUND_ROOT_H_
#define _ENTAGE_VIEW_COMPOUND_ROOT_H_

#include "ViewCompound.h"

namespace Entage
{
	template<class CompoundViewT> class ViewCompoundRoot : public CompoundViewT
	{
	public:

		ViewCompoundRoot() :
			contents(new TreeCompound)
		{
		}

		ViewCompoundRoot(TreeCompound* _contents) :
			contents(_contents)
		{
		}

		virtual TreeCompound* get_contents() { return contents.get(); }

		virtual const TreeCompound* get_contents() const { return contents.get(); }

	private:
		std::unique_ptr<TreeCompound> contents;
	};

}

#endif