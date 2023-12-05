#include "ProcessStorage.hpp"
namespace PSF::process
{
    void ProcessStorage::storeProcess(Process process, unsigned adress)
    {
        for (unsigned i{0}; i < queue.size(); ++i)
        {
            if (process.getId() == queue[i].getId())
            {
                queue.erase(queue.begin() + i);
            }
        }
        storage.emplace(adress, process);
    }

    void ProcessStorage::addProcessToQueue(Process process)
    {
        queue.emplace_back(process);
    }

    bool ProcessStorage::isProcessQueueEmpty()
    {
        return queue.empty();
    }

    const std::vector<Process> &ProcessStorage::getQueue()
    {
        return queue;
    }

    std::map<unsigned, Process> ProcessStorage::getFinishedProcesses()
    {
        std::map<unsigned, Process> finishedProcesses{};
        for (auto &[adress, process] : storage)
        {
            if (process.isFinished())
            {
                finishedProcesses.emplace(adress, process);
            }
        }

        for (auto &[adress, process] : finishedProcesses)
        {
            storage.erase(adress);
        }

        return finishedProcesses;
    }
}