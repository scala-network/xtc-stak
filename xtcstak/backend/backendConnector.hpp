#pragma once

#include "iBackend.hpp"
#include "miner_work.hpp"

#include <thread>
#include <vector>
#include <atomic>
#include <mutex>


namespace xtcstak
{

	struct BackendConnector
	{
		static std::vector<iBackend*>* thread_starter(miner_work& pWork);
		static bool self_test();
	};

} // namespace xtcstak
