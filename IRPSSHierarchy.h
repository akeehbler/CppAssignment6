
#ifndef IRPSS_HIERARCHY_HEADER
#define IRPSS_HIERARCHY_HEADER

#include <memory>
#include <iostream>
#include "Punches.h"
#include "NorthAmericanMember.h"
#include "SouthAmericanMember.h"

template <class T>
class IRPSSHierArchy {
    private:
        T member;
        unique_ptr<IRPSSHierArchy> left;
        unique_ptr<IRPSSHierArchy> right; 
    public:
        IRPSSHierArchy();
        IRPSSHierArchy(T _member);
        //TODO: void?
        void Insert(T new_member);
        friend ostream& operator<<(ostream& out, const IRPSSHierArchy& hierarchy);

}