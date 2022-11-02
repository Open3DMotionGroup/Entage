/*--
  Entage

	Copyrighted material. See LICENSE.txt for more information.
--*/

#ifndef _ENTAGE_MAP_ARRAY_H_
#define _ENTAGE_MAP_ARRAY_H_

#include "MapBase.h"
#include "Entage/Tree/TreeArray.h"

namespace Entage
{
	template<typename T> class MapArray : public MapBase< TreeArray<T> >
	{
	private:
		static const TreeArray<T> empty_array;

	public:
		MapArray(ViewCompound* _container, const std::string& _name, const std::string& _element_name = "X") :
			MapBase< TreeArray<T> >(_container, _name),
			element_name(_element_name),
			contents(nullptr)
		{
		}

		size_t size() const
		{
			const TreeArray<T>* current_array = get_array();
			return (current_array != nullptr) ? current_array->size() : 0;
		}

		typename TreeArray<T>::const_iterator begin() const
		{
			const TreeArray<T>* current_array = get_array();
			return (current_array != nullptr) ? current_array->begin() : empty_array.begin();
		}

		typename TreeArray<T>::const_iterator end() const
		{
			const TreeArray<T>* current_array = get_array();
			return (current_array != nullptr) ? current_array->end() : empty_array.end();
		}

		typename TreeArray<T>::iterator begin()
		{
			return get_or_create_array()->begin();
		}

		typename TreeArray<T>::iterator end()
		{
			return get_or_create_array()->end();
		}

		void clear()
		{
			get_or_create_array()->clear();
		}

		void add(const T& value)
		{
			get_or_create_array()->push_back(value);
		}

		T& operator[](size_t index)
		{
			get_array();
			return contents->at(index);
		}

		const T& operator[](size_t index) const
		{
			// Yes this will break if there is no collection
			// But that is just equivalent to bad array index
			return get_array()->at(index);
		}

	private:

		const TreeArray<T>* get_array() const
		{
			if (contents == nullptr)
			{
				contents = const_cast<TreeArray<T>*>(MapBase< TreeArray<T> >::lookup());
			}

			return contents;
		}

		TreeArray<T>* get_or_create_array()
		{
			if (get_array() == nullptr)
			{
				contents = new TreeArray<T>(element_name);
				MapBase< TreeArray<T> >::set(contents);
			}

			return contents;
		}


	private:
		const std::string element_name;
		mutable TreeArray<T>* contents;
	};
}

#endif