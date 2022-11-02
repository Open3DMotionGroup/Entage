
add_library (Entage STATIC
  Tree/Types.cpp Tree/Types.h
  Tree/TreeElement.cpp Tree/TreeElement.h
  Tree/TreeValue.cpp Tree/TreeValue.h
  Tree/TreeArray.cpp Tree/TreeArray.h
  Tree/TreeCompound.cpp Tree/TreeCompound.h
  Tree/TreeArrayCompound.cpp Tree/TreeArrayCompound.h
	Map/ViewCompound.cpp Map/ViewCompound.h
	Map/ViewCompoundRoot.cpp Map/ViewCompoundRoot.h
	Map/MapBase.cpp Map/MapBase.h
	Map/MapValue.cpp Map/MapValue.h
	Map/MapArray.cpp Map/MapArray.h
	Map/MapCompound.cpp Map/MapCompound.h
	IO/JSON.cpp IO/JSON.h)

target_include_directories(Entage PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../")
