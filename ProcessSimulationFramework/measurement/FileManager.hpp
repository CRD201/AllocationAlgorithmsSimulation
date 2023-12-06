#pragma once

#include <fstream>
#include <filesystem>
#include <iostream>

namespace PSF::measurement
{
    class FileManager
    {
    public:
        FileManager(const std::string &filename)
        {
            file.open(std::filesystem::current_path().parent_path().append(filename));
            file << "Iteration,";
            file << "algorithmTimeMeasurements.oneItertionTime,";
            file << "algorithmTimeMeasurements.totalTime,";
            file << "mmStructureAllocationTimeMeasurements.oneItertionTime,";
            file << "mmStructureAllocationTimeMeasurements.totalTime,";
            file << "mmStructureMemoryFreeingTimeMeasurements.oneItertionTime,";
            file << "mmStructureMemoryFreeingTimeMeasurements.totalTime,";
            file << "fragmentationSize\n";
        }

        ~FileManager()
        {
            file.close();
        }

        std::ofstream& operator()()
        {
            return file;
        }

    private:
        std::ofstream file{};
    };
}