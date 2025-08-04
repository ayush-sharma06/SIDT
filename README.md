# MyGameEngine

A modular, cross-platform C++ game engine designed from the ground up. MyGameEngine provides core systems—logging, event dispatch, window creation, and layered application architecture—to accelerate the development of 2D/3D games and interactive experiences.

---

## 📖 Overview

MyGameEngine is a lightweight, header-only C++17 engine focused on simplicity, flexibility, and performance. It abstracts away platform-specific details (Windows, macOS, Linux) and exposes a clean API for:

* **Logging & Diagnostics**
* **Event Handling**
* **Window Management**
* **Application Layering**

With these foundational systems in place, you can build game loops, renderers, and gameplay features on top without reinventing the wheel.

---

## ⚙️ Features & Modules

### 1. Logging & Diagnostics

* **Multi-level logging** (Trace, Info, Warning, Error, Critical)
* **Compile-time control** to enable/disable levels for production builds
* **Console & file sinks** out-of-the-box
* **Timestamped entries** and customizable formatting

### 2. Event System

* **Type-safe events** with compile-time registration
* **Event categories** (InputEvent, WindowEvent, CustomEvent, etc.)
* **Layer-based dispatch**: events traverse a stack of layers until handled

### 3. Window Abstraction

* **Cross-platform support** using SDL2 (or GLFW) under the hood
* **Configurable window properties**: title, size, fullscreen, vsync
* **Window events** (resize, close, focus) seamlessly integrated into event system

### 4. Layered Architecture

* **Layer stack**: push/pop layers and overlays at runtime
* **Layer lifecycle callbacks**: `OnAttach()`, `OnDetach()`, `OnUpdate()`, `OnEvent()`
* **Separation of concerns**: rendering layers, UI layers, gameplay layers, etc.

---

## 🛠️ Getting Started

### Prerequisites

* C++17-capable compiler (GCC ≥ 7.0, Clang ≥ 5.0, MSVC ≥ 2017)
* [CMake](https://cmake.org/) ≥ 3.12
* SDL2 (or GLFW) development libraries installed

### Clone & Build

```bash
git clone https://github.com/<your-username>/MyGameEngine.git
cd MyGameEngine
mkdir build && cd build
cmake ..
cmake --build .
```

---

## 🚀 Usage Example

```cpp
#include "Engine.h"

class ExampleLayer : public myge::Layer {
public:
    ExampleLayer() : Layer("Example") {}
    void OnAttach() override {
        MYGE_INFO("ExampleLayer attached");
    }
    void OnUpdate(float deltaTime) override {
        // game logic here
n    }
    void OnEvent(myge::Event& e) override {
        if (e.GetEventType() == myge::EventType::KeyPressed) {
            MYGE_TRACE("Key pressed event received");
        }
    }
};

int main() {
    myge::EngineConfig config;
    config.Title = "My Game";
    config.Width = 1280;
    config.Height = 720;

    myge::Engine engine(config);
    engine.PushLayer(std::make_shared<ExampleLayer>());
    engine.Run();

    return 0;
}
```

---

## 📚 Folder Structure

```
MyGameEngine/
├── include/          # Public headers
│   ├── Engine.h      # Core engine entry
│   ├── Application.h # App & layer definitions
│   ├── Log.h         # Logging macros & API
│   ├── Event.h       # Event base types
│   ├── Window.h      # Window abstraction
│   └── ...
├── src/              # Engine implementation files
├── examples/         # Example applications and demos
├── thirdparty/       # External dependencies (SDL2, etc.)
├── CMakeLists.txt    # Build configuration
└── README.md         # This file
```

---

## ✔️ Contributing

Contributions are welcome! To add features or fix issues:

1. Fork the repository
2. Create a feature branch (`git checkout -b feat/YourFeature`)
3. Implement your changes and add/adjust unit tests
4. Submit a pull request with a clear description

Please follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).

---

