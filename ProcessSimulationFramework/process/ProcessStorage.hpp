#pragma once

#include <map>
#include <vector>
#include "Process.hpp"

namespace PSF::process
{
    class ProcessStorage
    {
    public:
        void storeProcess(Process process, unsigned adress);
        void addProcessToQueue(Process process);
        bool isProcessQueueEmpty();
        const std::vector<Process>& getQueue();
        std::map<unsigned, Process> getFinishedProcesses();

    private:
        std::map<unsigned, Process> storage{};
        std::vector<Process> queue{};
    };
}