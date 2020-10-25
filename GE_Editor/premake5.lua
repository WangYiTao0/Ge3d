
    project "GE_Editor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-obj/" .. outputdir .. "/%{prj.name}")

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
		"%{wks.location}/Ge3d/3rdPart/spdlog/include",
        "%{wks.location}/Ge3d/src",
		"%{wks.location}/Ge3d/3rdPart",
		"%{IncludeDir.glm}",
		--"../Ge3d/%{IncludeDir.Glad}",
		--"../Ge3d/%{IncludeDir.ImGui}"
		"../Ge3d/%{IncludeDir.entt}",
    }

    links
    {
        "Ge3d",
	}
	
	defines
    {

    }

filter "system:windows"
    systemversion "latest"

    defines
    {
    }

	filter "configurations:Debug"
		defines "JF_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "JF_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "JF_DIST"
		optimize "On"
