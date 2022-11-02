/*--
  Entage

	Copyrighted material. See LICENSE.txt for more information.
--*/

#ifndef _ENTAGE_COMPOUND_H_
#define _ENTAGE_COMPOUND_H_

#include "TreeElement.h"
#include "Types.h"
#include <unordered_map>

namespace Entage
{
	class TreeCompound : public TreeElement
	{
	public:
		class Element
		{
		public:
			Element(Element& src) :
				name(src.name),
				value(src.release())
			{
			}

			Element(const std::string& _name, TreeElement* _value) :
				name(_name), value(_value)
			{

			}

			~Element()
			{
			}

			Element& operator=(Element& src)
			{
				name = src.name;
				value.reset(src.release());
			}

			const std::string& get_name() const
			{ return name; }

			const TreeElement* get_value() const
			{ return value.get(); }

			TreeElement* get_value()
			{ return value.get(); }

			TreeElement* release()
			{
				name.clear();
				return value.release();
			}

		private:
			std::string name;
			std::unique_ptr<TreeElement> value;
		};

	public:
		TreeCompound() :
			TreeElement(get_value_type<TreeCompound>())
		{
		}

		void set(const std::string& name, TreeElement* value)
		{
			content.push_back(Element(name, value));
			lookup[name] = content.size() - 1;
		}

		const TreeElement* get(const std::string& name) const
		{
			std::unordered_map<std::string, size_t>::const_iterator lookup_iter = lookup.find(name);
			return (lookup_iter != lookup.end()) ? get(lookup_iter->second) : nullptr;
		}

		TreeElement* get(const std::string& name)
		{
			std::unordered_map<std::string, size_t>::const_iterator lookup_iter = lookup.find(name);
			return (lookup_iter != lookup.end()) ? get(lookup_iter->second) : nullptr;
		}

		template<class T> T* get_type(const std::string& name)
		{
			return TreeElementCast<T>(get(name));
		}

		template<class T> const ValueType* get_type(const std::string& name) const
		{
			return TreeElementCast<T>(get(name));
		}

		const TreeElement* get(size_t index) const
		{
			return content[index].get_value();
		}

		TreeElement* get(size_t index)
		{
			return content[index].get_value();
		}

		void remove(std::string& name)
		{
			TreeElement* value = detach(name);
			if (value)
			{
				delete value;
			}
		}

		TreeElement* detach(std::string& name)
		{
			TreeElement* result = nullptr;
			std::unordered_map<std::string, size_t>::iterator lookup_iter = lookup.find(name);
			if (lookup_iter != lookup.end())
			{
				size_t index = lookup_iter->second;
				std::vector<Element>::iterator content_iter = content.begin() + index;
				result = content_iter->release();
				content.erase(content_iter);
				lookup.erase(lookup_iter);
			}
			return result;
		}

		void clear()
		{
			content.clear();
			lookup.clear();
		}

		using const_iterator = std::vector<Element>::const_iterator;

		const_iterator begin() const
		{ return content.begin(); }

		const_iterator end() const
		{ return content.end(); }

	private:
		std::vector<Element> content;
		std::unordered_map<std::string, size_t> lookup;
	};

}

#endif