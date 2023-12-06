#pragma once

#include <utility>
#include <random>
#include "Process.hpp"

namespace PSF::process
{
    class ProcessFactory
    {
        using ProcessThreshold = std::pair<unsigned, unsigned>;

    public:
        explicit ProcessFactory(const unsigned memorySize);

        Process spawnProcess();

    private:
        ProcessThreshold calculateSmallProcessSize(const unsigned memorySize);
        ProcessThreshold calculateMediumProcessSize(const unsigned memorySize);
        ProcessThreshold calculateLargeProcessSize(const unsigned memorySize);

        unsigned getProcessId();
        unsigned getProcessSize();
        unsigned calculateProcessSize(ProcessThreshold processSizeThreshold);
        unsigned getProcessLifeCycle();

        // Distribution of processes by size
        // 20% of small - 0.01% - 0.1% memory
        // 60% of medium - 0.1% - 1.0% memory
        // 20% of large - 1.0% - 4.0% memory

        static constexpr double smallProcessThreshold{0.3};
        static constexpr double mediumProcessThreshold{0.85};

        const ProcessThreshold smallProcessSize;
        const ProcessThreshold mediumProcessSize;
        const ProcessThreshold largeProcessSize;

        static constexpr ProcessThreshold processLifeCycleThreshold{50, 150}; // number of iteration

        unsigned processIdCounter{0};

        std::mt19937 generator{0};
    };
}