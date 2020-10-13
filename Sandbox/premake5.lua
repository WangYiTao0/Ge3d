
    project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"src/**.cpp"
    }
    
    includedirs
    {
        "../Ge3d/3rdPart/spdlog/include",
        "../Ge3d/src",
		"../JFEngine/3rdPart",
        "../JFEngine/%{IncludeDir.ImGui}",
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
        "../Ge3d/3rdPart/assimp/bin/Debug/assimp-vc142-mtd.lib"
    }

    postbuildcommands 
    {
        '{COPY} "../Ge3d/3rdPart/assimp/bin/Debug/assimp-vc142-mtd.dll" "%{cfg.targetdir}"'
    }

filter "configurations:Release"
    defines "GE_RELEASE"
    runtime "Release"
    optimize "on"
    links
    {
        "../Ge3d/3rdPart/assimp/bin/Release/assimp-vc142-mtd.lib"
    }

    postbuildcommands 
    {
        '{COPY} "../Ge3d/3rdPart/assimp/bin/Release/assimp-vc142-mt.dll" "%{cfg.targetdir}"'
    }

filter "configurations:Dist"
    defines "GE_DIST"
    optimize "On"

    links
    {
        "../Ge3d/3rdPart/assimp/bin/Release/assimp-vc142-mtd.lib"
    }

    postbuildcommands 
    {
        '{COPY} "../Ge3d/3rdPart/assimp/bin/Release/assimp-vc142-mt.dll" "%{cfg.targetdir}"'
    }
