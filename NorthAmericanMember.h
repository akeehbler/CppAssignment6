
#ifndef NORTH_AMERICAN_MEMBER_HEADER
#define NORTH_AMERICAN_MEMBER_HEADER

#include <string>
#include <vector>
#include <iostream>
#include "Punches.h"

using namespace std;

class NorthAmericanMember {
    private:
        string name;
        vector<char> strategy;
        int strength;
        bool schoolOfRock;
        bool paperTiger;
    public:
        
        NorthAmericanMember(){}

        NorthAmericanMember(string _name, int _strength, vector<char> _strategy, bool _rockSchool, bool _tiger){
            name = _name;
            strength = _strength;
            strategy = _strategy;
            schoolOfRock = _rockSchool;
            paperTiger = _tiger;
        }
        
        //TODO: friend?
        friend bool operator<(const NorthAmericanMember& defender){
            // dot or ->?
            if((this->schoolOfRock && defender.paperTiger) || (this->paperTiger && defender.schoolOfRock)){
                // new operator here or not?
                throw Punches(this->strength, defender.strength);
            }
            int offenderScore = 0;
            int defenderScore = 0;
            char offenderMove;
            char defenderMove;

            for(int i = 0; i < this->strategy.size(); i++){
                offenderMove = this->strategy.at(i);
                defenderMove = defender.strategy.at(i);
                if((offenderMove == 'r' && defenderMove == 'p') ||
                   (offenderMove == 'p' && defenderMove == 's') ||
                   (offenderMove == 's' && defenderMove == 'r')){
                    defenderScore++;

                }else if((defenderMove == 'r' && offenderMove == 'p') ||
                         (defenderMove == 'p' && offenderMove == 's') ||
                         (defenderMove == 's' && offenderMove == 'r')){
                             offenderScore++;
                         }
                if(defenderScore >= 3){
                    return true;
                }
                if(offenderScore >= 3){
                    return false;
                }
            }
            //Reached end of loop so neither player got to 3
            if(defenderScore > offenderScore){
                return true;
            }else if(offenderScore > defenderScore){
                return false;
            }
            // If reach here, scores were tied so defender wins = return true
            return true;
        }
        
        //TODO: friend?
        friend ostream& operator<<(ostream& out, const NorthAmericanMember& member){
            out << member.name;
            if(member.schoolOfRock){
                out << " (School of Rock)" << endl;
            }
            else if(member.paperTiger){
                out << " (Paper Tigers)" << endl;
            }
            return out;
        }

}

#endif