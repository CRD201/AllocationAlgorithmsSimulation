#pragma once

#include <chrono>
#include <string>

#include "FileManager.hpp"

namespace PSF::measurement
{
    class MeasurementHandler
    {
        using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;

        struct TimeMeasurements
        {
            TimePoint startTime{};
            TimePoint stopTime{};
            std::chrono::microseconds oneItertionTime{0};
            std::chrono::microseconds totalTime{0};
        };

    public:
        void startAlgorithmTimeMeasurement();
        void endAlgorithmTimeMeasurement();
        void startMMStructureAllocationTimeMeasurement();
        void endMMStructureAllocationTimeMeasurement();
        void startMMStructureMemoryFreeingTimeMeasurement();
        void endMMStructureMemoryFreeingTimeMeasurement();
        void setFragmentationSize(const unsigned size);
        void saveData();

    private:
        void calculateTime(TimeMeasurements& timeMeasurements);

        TimeMeasurements algorithmTimeMeasurements;
        TimeMeasurements mmStructureAllocationTimeMeasurements;
        TimeMeasurements mmStructureMemoryFreeingTimeMeasurements;
        unsigned fragmentationSize{0};
        unsigned numberOfIteration{0};

        const std::string filename{"measurements.csv"};
        FileManager fileManager{filename};
    };
}