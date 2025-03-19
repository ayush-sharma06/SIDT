// For now we have only added windows support for our SIDT as we verify if SD_PLATFORM_WINDOWS is defined
// Added functionalities to switch between Engine modes like Simulation and Event Based
// Mode switching: if in simulation mode, run continuous updates;
// if in CAD mode, run event-based processing.
// Simulation Mode: Continuous Loop (update every frame)
// CAD Mode: Event-driven; update only when an event occurs.
// Here, you would call an event-processing function instead of Run().
// For example, you could add a new method in Application: OnEventProcessing().
// For now, if you haven't implemented it, you can simulate with a simple loop.


#pragma once

#include "EngineMode.h"


#ifdef SD_PLATFORM_WINDOWS
extern SIDT::Application* SIDT::CreateApplication();

int main(int argc, char** argv)
{
    SIDT::Log::Init();
    auto app = SIDT::CreateApplication();
    auto layer = SIDT::Layer();

    if (g_ExecutionMode == ExecutionMode::SIMULATION_MODE)
    {
        SD_CORE_WARN("Initialized Log!");
        SD_INFO("Hello!");
        while (true) // Or use a proper IsRunning() check if available
        {
            app->Run(); // Your current Run() function (or OnUpdate() if you add one)
        }
    }
    else // g_ExecutionMode == ExecutionMode::CAD_MODE
    {
        SD_CORE_WARN("Initialized Log!");
        SD_INFO("Hello!");
        app->Run();
    }
    delete app;
}

#else
#error "SIDT only support Windows!"
#endif