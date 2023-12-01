#pragma once

namespace MML::common
{
    class Hole
    {
    public:
        explicit Hole(unsigned adress, unsigned size) : adress{adress}, size{size} {}

        inline unsigned getAdress() const { return adress; }
        inline unsigned getSize() const { return size; }

    private:
        const unsigned adress;
        const unsigned size;
    };
}