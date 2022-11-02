#include "JSON.h"
#include "Entage/Tree/TreeValue.h"
#include "Entage/Tree/TreeArray.h"
#include "Entage/Tree/TreeCompound.h"
#include "Entage/Tree/TreeArrayCompound.h"

namespace Entage
{
	template<typename ValueT> void append_json_value(std::ostream& os, const TreeValue<ValueT>& v);
	template<typename ValueT> void append_json_array(std::ostream& os, const TreeArray<ValueT>& v);
	void append_json_compound(std::ostream& os, const TreeCompound& v);
	void append_json_compound_array(std::ostream& os, const TreeArrayCompound& v);
	
	void append_json(std::ostream& os, const TreeElement& v)
	{
		switch (v.instance_type)
		{
			case value_type_compound:
				append_json_compound(os, static_cast<const TreeCompound&>(v));
				break;
			case value_type_compound_array:
				append_json_compound_array(os, static_cast<const TreeArrayCompound&>(v));
				break;
			case value_type_bool:
				append_json_value<bool>(os, static_cast<const TreeValue<bool>&>(v));
				break;
			case value_type_bool_array:
				append_json_array<bool>(os, static_cast<const TreeArray<bool>&>(v));
				break;
			case value_type_int32:
				append_json_value<int32_t>(os, static_cast<const TreeValue<int32_t>&>(v));
				break;
			case value_type_int32_array:
				append_json_array<int32_t>(os, static_cast<const TreeArray<int32_t>&>(v));
				break;
			case value_type_float64:
				append_json_value<double>(os, static_cast<const TreeValue<double>&>(v));
				break;
			case value_type_float64_array:
				append_json_array<double>(os, static_cast<const TreeArray<double>&>(v));
				break;
			case value_type_string:
				append_json_value<std::string>(os, static_cast<const TreeValue<std::string>&>(v));
				break;
			case value_type_string_array:
				append_json_array<std::string>(os, static_cast<const TreeArray<std::string>&>(v));
				break;
		}
	}

	template<typename ValueT> void append_json_value(std::ostream& os, const TreeValue<ValueT>& v)
	{
		os << (const ValueT&) v;
	}

	template<typename ValueT> void append_json_array(std::ostream& os, const TreeArray<ValueT>& v)
	{
		os << "[ ";
		for (TreeArray<ValueT>::const_iterator iter(v.begin()); iter != v.end(); iter++)
		{
			if (iter != v.begin())
			{
				os << ", ";
			}

			os << *iter;
		}
		os << " ]";
	}

	void append_json_compound(std::ostream& os, const TreeCompound& v)
	{
		os << "{ ";
		for (TreeCompound::const_iterator iter(v.begin()); iter != v.end(); iter++)
		{
			if (iter != v.begin())
			{
				os << ", ";
			}
			os << iter->get_name() << ": ";
			append_json(os, *iter->get_value());
		}
		os << " }";
	}

	void append_json_compound_array(std::ostream& os, const TreeArrayCompound& v)
	{
		os << "[ ";
		for (TreeArrayCompound::const_iterator iter(v.begin()); iter != v.end(); iter++)
		{
			if (iter != v.begin())
			{
				os << ", ";
			}
			append_json(os, **iter);
		}
		os << " ]";
	}
}