cmake_minimum_required(VERSION 2.6)
#acknowledge policy push/pop
cmake_policy(SET CMP0011 NEW) 

project("c-seminar")

set(CMAKE_MODULE_PATH 
	"${CMAKE_MODULE_PATH}"
	"${PROJECT_SOURCE_DIR}/cmake/modulartex/cmake"
	"${PROJECT_SOURCE_DIR}/cmake/arcb/cmake"
	)

# list of projects to build
set(projects 
	"creview"
	"sampleCode"
	)

#build the project infos
foreach(proj ${projects})
	add_subdirectory(${proj})
endforeach(proj)
