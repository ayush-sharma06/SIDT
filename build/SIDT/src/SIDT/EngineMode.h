#pragma once

enum class ExecutionMode {
	CAD_MODE,
	SIMULATION_MODE
};

static ExecutionMode g_ExecutionMode = ExecutionMode::CAD_MODE;
