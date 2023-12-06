#include "MeasurementHandler.hpp"

#include <iostream>

namespace PSF::measurement
{

    void MeasurementHandler::startAlgorithmTimeMeasurement()
    {
        algorithmTimeMeasurements.startTime = std::chrono::high_resolution_clock::now();
    }

    void MeasurementHandler::endAlgorithmTimeMeasurement()
    {
        algorithmTimeMeasurements.stopTime = std::chrono::high_resolution_clock::now();
        calculateTime(algorithmTimeMeasurements);
    }

    void MeasurementHandler::startMMStructureAllocationTimeMeasurement()
    {
        mmStructureAllocationTimeMeasurements.startTime = std::chrono::high_resolution_clock::now();
    }

    void MeasurementHandler::endMMStructureAllocationTimeMeasurement()
    {
        mmStructureAllocationTimeMeasurements.stopTime = std::chrono::high_resolution_clock::now();
        calculateTime(mmStructureAllocationTimeMeasurements);
    }

    void MeasurementHandler::startMMStructureMemoryFreeingTimeMeasurement()
    {
        mmStructureMemoryFreeingTimeMeasurements.startTime = std::chrono::high_resolution_clock::now();
    }

    void MeasurementHandler::endMMStructureMemoryFreeingTimeMeasurement()
    {
        mmStructureMemoryFreeingTimeMeasurements.stopTime = std::chrono::high_resolution_clock::now();
        calculateTime(mmStructureMemoryFreeingTimeMeasurements);
    }

    void MeasurementHandler::calculateTime(TimeMeasurements &timeMeasurements)
    {
        auto duration = duration_cast<std::chrono::microseconds>(timeMeasurements.stopTime - timeMeasurements.startTime);
        timeMeasurements.oneItertionTime += duration;
        timeMeasurements.totalTime += duration;
    }

    void MeasurementHandler::setFragmentationSize(const unsigned size)
    {
        fragmentationSize = size;
    }

    void MeasurementHandler::saveData()
    {
        fileManager() << numberOfIteration << ",";
        fileManager() << algorithmTimeMeasurements.oneItertionTime << ",";
        fileManager() << algorithmTimeMeasurements.totalTime << ",";
        fileManager() << mmStructureAllocationTimeMeasurements.oneItertionTime << ",";
        fileManager() << mmStructureAllocationTimeMeasurements.totalTime << ",";
        fileManager() << mmStructureMemoryFreeingTimeMeasurements.oneItertionTime << ",";
        fileManager() << mmStructureMemoryFreeingTimeMeasurements.totalTime << ",";
        fileManager() << fragmentationSize << "\n";

        numberOfIteration += 1;
        algorithmTimeMeasurements.oneItertionTime = static_cast<std::chrono::microseconds>(0);
        mmStructureAllocationTimeMeasurements.oneItertionTime = static_cast<std::chrono::microseconds>(0);
        mmStructureMemoryFreeingTimeMeasurements.oneItertionTime = static_cast<std::chrono::microseconds>(0);
    }
}