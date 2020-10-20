include "./3rdPart/premake/premake_customization/solution_items.lua"

workspace "Ge3d"
    architecture "x64"
    targetdir "build"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    solution_items
	{
		".editorconfig"
	}

    flags
    {
        "MultiProcessorCompile"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to 
IncludeDir = {}
IncludeDir["ImGui"] = "3rdPart/imgui"

-- Projects
group "Dependencies"
    include "3rdPart/premake"
    include "Ge3d/3rdPart/imgui"
    
group ""

include "Ge3d"
include "Sandbox"

