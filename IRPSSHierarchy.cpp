
#include "IRPSSHierarchy.h"

using namespace std;

IRPSSHierArchy::IRPSSHierArchy(){}

IRPSSHierArchy::IRPSSHierArchy(T _member){
    member = _member;
    left = nullptr;
    right = nullptr;
}

void IRPSSHierArchy::Insert(T new_member){
    bool belongsOnLeft = false;
    try{
        if(new_member < this.member){
            belongsOnLeft = true;
        }
    }catch(Punches p){
        p.what();
        if(p.challenger > p.defender){
            this.member = new_member;
        }
        return;
    }

    if(belongsOnLeft){
        if(this.left == nullptr){
            this.left = make_unique<IRPSSHierArchy>(new_member);
        }else{
            this.left.Insert(new_member);
        }
    }else{ //belongs on right
        if(this.right == nullptr){
            this.right = make_unique<IRPSSHierArchy>(new_member);
        }else{
            this.right.Insert(new_member);
        }
    }
    return;
}

ostream& operator<<(ostream& out, const IRPSSHierArchy& hierarchy){
    //TODO: Hierarchy here or use this? Also . or ->
    if(left != nullptr){
        out << hierarcy.left;
    }
    out << this->member;
    if(right != nullptr){
        out << hierarchy.right;
    }

    return out;
}
