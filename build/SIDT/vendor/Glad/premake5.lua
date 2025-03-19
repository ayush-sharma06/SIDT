project  "Glad"
    kind "StaticLib"
    language "C"
    
    targetdir("bin/" ..outputdir .. "/%{prj.name}")
    objdir("bin/" ..outputdir.. "/%{prj.name}")

    files{
        "include/glad/glad.h",
        "include/KHR/khrplatform.h",
        "src/glad.c"
    }

    includedirs{
        "include"
    }

    filter "system:windows"
        systemversion "latest"
    
    filter "Configurations: Debug"
        runtime "Debug"
        symbols "On"
    
    filter "Configurations: Release"
        runtime "Release"
        optimize "On"