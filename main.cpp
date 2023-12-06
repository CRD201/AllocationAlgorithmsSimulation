#define MEM_SIZE 100000
#define ITER_NUM 2000

#include "ProcessSimulationFramework/simulation/Simulation.hpp"

using PSF::simulation::Simulation;

int main()
{
    Simulation<MEM_SIZE, ITER_NUM>().setBestFit().setLinkedList().run();
    return 0;
}