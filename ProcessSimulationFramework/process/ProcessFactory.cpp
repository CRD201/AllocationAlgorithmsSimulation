#include <iostream>
#include "ProcessFactory.hpp"

namespace PSF::process
{
    ProcessFactory::ProcessFactory(const unsigned memorySize)
        : smallProcessSize{calculateSmallProcessSize(memorySize)},
          mediumProcessSize{calculateMediumProcessSize(memorySize)},
          largeProcessSize{calculateLargeProcessSize(memorySize)}
    {
    }

    ProcessFactory::ProcessThreshold ProcessFactory::calculateSmallProcessSize(const unsigned memorySize)
    {
        return ProcessThreshold(memorySize * 0.0001, memorySize * 0.001);
    }

    ProcessFactory::ProcessThreshold ProcessFactory::calculateMediumProcessSize(const unsigned memorySize)
    {
        return ProcessThreshold(memorySize * 0.001, memorySize * 0.01);
    }

    ProcessFactory::ProcessThreshold ProcessFactory::calculateLargeProcessSize(const unsigned memorySize)
    {
        return ProcessThreshold(memorySize * 0.01, memorySize * 0.04);
    }

    Process ProcessFactory::spawnProcess()
    {
        const auto processSize{getProcessSize()};
        const auto processLife{getProcessLifeCycle()};
        std::cout << "[PSF-INF] ProcessFactory: New process processSize: " << processSize << " processLife: " << processLife << std::endl;
        return Process(processSize, processLife);
    }

    unsigned ProcessFactory::getProcessSize()
    {
        std::uniform_real_distribution<double> processDistribution(0.0, 1.0);
        const auto generatedPercentage{processDistribution(generator)};
        if (generatedPercentage < smallProcessThreshold)
        {
            return calculateProcessSize(smallProcessSize);
        }
        if (generatedPercentage < mediumProcessThreshold)
        {
            return calculateProcessSize(mediumProcessSize);
        }
        return calculateProcessSize(largeProcessSize);
    }

    unsigned ProcessFactory::calculateProcessSize(ProcessThreshold processSizeThreshold)
    {
        std::uniform_int_distribution<unsigned>
            sizeDistribution(processSizeThreshold.first, processSizeThreshold.second);
        return sizeDistribution(generator);
    }

    unsigned ProcessFactory::getProcessLifeCycle()
    {
        std::uniform_int_distribution<unsigned>
            lifeCycleDistribution(processLifeCycleThreshold.first, processLifeCycleThreshold.second);
        return lifeCycleDistribution(generator);
    }
}