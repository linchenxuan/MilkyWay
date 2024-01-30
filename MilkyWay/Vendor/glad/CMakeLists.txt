add_library("Glad" STATIC
	"${CMAKE_CURRENT_SOURCE_DIR}/MilkyWay/Vendor/glad/include/KHR/khrplatform.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/MilkyWay/Vendor/glad/include/glad/glad.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/MilkyWay/Vendor/glad/src/glad.c"
)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set_source_files_properties(
		PROPERTIES
		GENERATED true
	)
	set_target_properties("Glad" PROPERTIES
		OUTPUT_NAME "Glad"
		ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Build/Bin/Debug/Glad"
		LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Build/Bin/Debug/Glad"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Build/Bin/Debug/Glad"
	)
	target_include_directories("Glad" PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/MilkyWay/Vendor/glad/include"
	)
	set_property(TARGET "Glad" PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL")
	set_target_properties("Glad" PROPERTIES LINK_FLAGS "-m64")
	target_compile_options("Glad" PRIVATE
		$<$<COMPILE_LANGUAGE:C>:-m64>
		$<$<COMPILE_LANGUAGE:C>:-g>
		$<$<COMPILE_LANGUAGE:CXX>:-m64>
		$<$<COMPILE_LANGUAGE:CXX>:-g>
	)
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Release")
	set_source_files_properties(
		PROPERTIES
		GENERATED true
	)
	set_target_properties("Glad" PROPERTIES
		OUTPUT_NAME "Glad"
		ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Build/Bin/Release/Glad"
		LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Build/Bin/Release/Glad"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Build/Bin/Release/Glad"
	)
	target_include_directories("Glad" PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/MilkyWay/Vendor/glad/include"
	)
	set_property(TARGET "Glad" PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
	set_target_properties("Glad" PROPERTIES LINK_FLAGS "-m64")
	target_compile_options("Glad" PRIVATE
		$<$<COMPILE_LANGUAGE:C>:-m64>
		$<$<COMPILE_LANGUAGE:C>:-O2>
		$<$<COMPILE_LANGUAGE:CXX>:-m64>
		$<$<COMPILE_LANGUAGE:CXX>:-O2>
	)
endif()