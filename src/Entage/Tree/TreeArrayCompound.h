/*--
  Entage

	Copyrighted material. See LICENSE.txt for more information.
--*/

#ifndef _ENTAGE_ARRAY_COMPOUND_H_
#define _ENTAGE_ARRAY_COMPOUND_H_

#include "TreeCompound.h"

namespace Entage
{
	class TreeArrayCompound : public TreeElement
	{
	public:
		TreeArrayCompound(const std::string& _element_name) :
			TreeElement(get_value_type<TreeArrayCompound>()),
			element_name(_element_name)
		{
		}

		void add(TreeCompound* value) { content.push_back(std::unique_ptr<TreeCompound>(value)); }

		void remove(size_t index) { content.erase(content.begin() + index); }

		void clear() { content.clear(); }

		TreeCompound* operator[](size_t index) { return content[index].get(); }

		const TreeCompound* operator[](size_t index) const { return content[index].get(); }

		const std::string& get_element_name() const { return element_name; }

		using const_iterator = std::vector< std::unique_ptr<TreeCompound> >::const_iterator;

		const_iterator begin() const
		{ return content.begin(); }

		const_iterator end() const
		{ return content.end(); }

	private:
		std::string element_name;
		std::vector< std::unique_ptr<TreeCompound> > content;
	};

}

#endif