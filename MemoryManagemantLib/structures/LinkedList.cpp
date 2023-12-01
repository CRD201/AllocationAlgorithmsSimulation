#include "LinkedList.hpp"

namespace MML::structures
{
    template <unsigned SIZE>
    LinkedList<SIZE>::LinkedList()
        : head{std::make_shared<Node>(true, 0, SIZE, nullptr)}, currectNode{head}
    {
    }

    template <unsigned SIZE>
    std::optional<common::Hole> LinkedList<SIZE>::getHole()
    {
        if (lastNodeReached() && isHoleFound)
        {
            return std::nullopt;
        }

        if (isHoleFound)
        {
            currectNode = currectNode->next;
        }

        while (!currectNode->isHole)
        {
            if (lastNodeReached())
            {
                return nullptr;
            }
            currectNode = currectNode->next;
        }

        return std::make_optional<common::Hole>(currectNode->adress, currectNode->size);
    }

    template <unsigned SIZE>
    bool LinkedList<SIZE>::lastNodeReached()
    {
        if (currectNode->next == nullptr)
        {
            return true;
        }
        return false;
    }

    template <unsigned SIZE>
    std::shared_ptr<typename LinkedList<SIZE>::Node> LinkedList<SIZE>::findNodeByAdress(unsigned adress)
    {
        std::shared_ptr<Node> tmpNode{head};
        while (tmpNode->adress < adress)
        {
            if (tmpNode->next == nullptr)
            {
                return nullptr;
            }
            tmpNode = tmpNode->next;
        }
        return tmpNode;
    }

    template <unsigned SIZE>
    void LinkedList<SIZE>::fillHole(unsigned spaceToFill)
    {
        currectNode->isHole = false;

        if (currectNode->size > spaceToFill)
        {
            std::shared_ptr<Node> newHole{std::make_shared<Node>(true,
                                                                 currectNode->adress + spaceToFill,
                                                                 currectNode->size - spaceToFill,
                                                                 currectNode->next)};
            currectNode->size = spaceToFill;
            currectNode->next = newHole;
        }
    }

    template <unsigned SIZE>
    void LinkedList<SIZE>::freeSpace(unsigned adress, unsigned spaceToFree)
    {
        std::shared_ptr<Node> newHole = findNodeByAdress(adress);

        std::shared_ptr<Node> tmpNode{head};
        while (tmpNode->next != nullptr)
        {
            if (tmpNode->isHole || tmpNode->next->isHole)
            {
                tmpNode->size += tmpNode->next->size;
                tmpNode->next = tmp->next->next;
            }
            else
            {
                tmpNode = tmpNode->next;
            }
        }
    }
}