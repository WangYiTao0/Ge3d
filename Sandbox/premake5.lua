
    project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

    buildoptions
    {
        "/permissive-",
        "/sdl",
        "/w34265",
    }

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-obj/" .. outputdir .. "/%{prj.name}")


    characterset ("MBCS")

    flags
    {
        "MultiProcessorCompile"
    }

	files
	{
	    "src/**.h", 
	    "src/**.c", 
	    "src/**.hpp", 
	    "src/**.cpp" ,
        "asset/shader/**.hlsl",
        "asset/shader/**.hlsli",
    }
    
    includedirs
    {
        "../Ge3d/3rdPart/spdlog/include",
        "../Ge3d/src",
		"../Ge3d/3rdPart",
        "../Ge3d/%{IncludeDir.ImGui}",
        "../Ge3d/%{IncludeDir.DirectXTex}",
        "../Ge3d/%{IncludeDir.assimp}",
    }

    links
    {
        "Ge3d"
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

    links
    {
        "../Ge3d/3rdPart/assimp/lib/Debug/assimp-vc142-mtd.lib",
        "../Ge3d/3rdPart/assimp/lib/Debug/IrrXMLd.lib",
        "../Ge3d/3rdPart/DirectXTex/lib/Debug/DirectXTex.lib"
    }

    postbuildcommands 
    {
        '{COPY} "../Ge3d/3rdPart/assimp/lib/Debug/assimp-vc142-mtd.dll" "%{cfg.targetdir}"',
        '{COPY} "../Ge3d/3rdPart/assimp/lib/Debug/zlibd1.dll" "%{cfg.targetdir}"',
    }

filter "configurations:Release"
    defines "GE_RELEASE"
    runtime "Release"
    optimize "on"
    links
    {
        "../Ge3d/3rdPart/assimp/lib/Release/assimp-vc142-mt.lib",
        "../Ge3d/3rdPart/assimp/lib/Release/IrrXML.lib",
        "../Ge3d/3rdPart/DirectXTex/lib/Release/DirectXTex.lib",
    }

    postbuildcommands 
    {
        '{COPY} "../Ge3d/3rdPart/assimp/lib/Release/assimp-vc142-mt.dll" "%{cfg.targetdir}"',
        '{COPY} "../Ge3d/3rdPart/assimp/lib/Release/zlib1.dll" "%{cfg.targetdir}"',
    }

filter "configurations:Dist"
    defines "GE_DIST"
    optimize "On"

    links
    {
        "../Ge3d/3rdPart/assimp/lib/Release/assimp-vc142-mt.lib",
        "../Ge3d/3rdPart/assimp/lib/Release/IrrXML.lib",
        "../Ge3d/3rdPart/DirectXTex/lib/Release/DirectXTex.lib",
    }

    postbuildcommands 
    {
        '{COPY} "../Ge3d/3rdPart/assimp/lib/Release/assimp-vc142-mt.dll" "%{cfg.targetdir}"',
        '{COPY} "../Ge3d/3rdPart/assimp/lib/Release/zlib1.dll" "%{cfg.targetdir}"',
    }
