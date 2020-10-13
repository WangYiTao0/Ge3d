project "Ge3d"
kind "StaticLib"
language "c++"
cppdialect "c++17"
staticruntime "on"

targetdir("../bin/" .. outputdir .. "/%{prj.name}")
objdir("../bin-obj/" .. outputdir .. "/%{prj.name}")

pchheader "gepch.h"
pchsource "src/gepch.cpp"

characterset ("MBCS")

buildoptions
{
    "/permissive-",
    "/sdl",
    "/w34265",
}

files
{
	"src/**.h", 
	"src/**.c", 
	"src/**.hpp", 
	"src/**.cpp" 
}

defines
{
    "_CRT_SECURE_NO_WARNINGS"
}

includedirs
{
    "src",
    "%{IncludeDir.ImGui}",
    "3rdPart/spdlog/include",
    "3rdPart/assimp/include",
    "3rdPart/DirectXTex/include",
}

links
{
    "ImGui",
    "d3d11.lib",
    "D3DCompiler.lib",
}

filter "system:windows"
    systemversion "latest"

    defines
    {
    
    }

filter "configurations:Debug"
    defines "GE_DEBUG"
    runtime "Debug"
    symbols "on"

    defines
    {
        "IS_DEBUG=true"
    }

    links
    {
        "3rdPart/DirectXTex/lib/Debug/DirectXTex.lib"
    }

filter "configurations:Release"
    defines "GE_RELEASE"
    runtime "Release"
    optimize "on"

    
    defines
    {
        "IS_DEBUG=false",
        "NDEBUG"
    }

    links
    {
        "3rdPart/DirectXTex/lib/Release/DirectXTex.lib"
    }