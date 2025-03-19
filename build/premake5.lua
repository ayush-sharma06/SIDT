workspace "SIDT"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "SIDT/vendor/GLFW/include"
IncludeDir["Glad"] = "SIDT/vendor/Glad/include"
IncludeDir["ImGui"] = "SIDT/vendor/imgui"

include "SIDT/vendor/GLFW"
include "SIDT/vendor/Glad"
include "SIDT/vendor/imgui"

project "SIDT"
    location "SIDT"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "sdpch.h"
    pchsource "SIDT/src/sdpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"
        buildoptions { "/utf-8" }

        defines
        {
            "SD_PLATFORM_WINDOWS",
            "SD_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Simulation")
        }
    
    filter "Configurations:Debug"
        defines "SD_DEBUG"
        buildoptions "/MDd"
        symbols "On"
    filter "Configurations:Release"
        defines "SD_RELEASE"
        buildoptions "/MD"
        optimize "On"
    filter "Configurations:Dist"
        defines "SD_DIST"
        buildoptions "/MD"
        optimize "On"

project "Simulation"
    location "Simulation"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "SIDT/vendor/spdlog/include",
        "SIDT/src"
    }

    links
    {
        "SIDT"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"
        buildoptions { "/utf-8" }

        defines
        {
            "SD_PLATFORM_WINDOWS"
        }

    filter "Configurations:Debug"
        defines "SD_DEBUG"
        buildoptions "/MDd"
        symbols "On"
    filter "Configurations:Release"
        defines "SD_RELEASE"
        buildoptions "/MD"
        optimize "On"
    filter "Configurations:Dist"
        defines "SD_DIST"
        buildoptions "/MD"
        optimize "On"