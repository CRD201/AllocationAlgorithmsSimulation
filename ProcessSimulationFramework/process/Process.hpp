#pragma once

namespace PSF::process
{
    class Process
    {
    public:
        explicit Process(const unsigned processSize, const unsigned numberOfLifeCycles)
            : processId{calculateId()},
              processSize{processSize},
              numberOfLifeCycles{numberOfLifeCycles}
        {
        }

        inline unsigned getId()
        {
            return processId;
        }

        inline unsigned getSize()
        {
            return processSize;
        }

        inline bool isFinished()
        {
            numberOfLifeCycles -= 1;
            if (numberOfLifeCycles <= 0)
            {
                return true;
            }
            return false;
        }

    private:
        inline unsigned calculateId()
        {
            static unsigned processIdCounter{0};
            processIdCounter += 1;
            return processIdCounter;
        }

        unsigned processId;
        unsigned processSize;

        unsigned numberOfLifeCycles;
    };
}