#ifndef RULEMANAGER_H
#define RULEMANAGER_H

#include <iostream>
#include <vector>
#include <map>
#include "element.h"

class RuleManager
{
    private:
        std::map<Element,std::vector<Element>> rules;
        static const std::vector<Element> leftWords;
        static const std::vector<Element> rightWords;

    public:
        inline RuleManager();

        inline RuleManager(const std::vector<Element> & subject,const Element & complement);

        inline void addRule(const Element & complement,const Element & subject);

        inline void removeRule(const Element & complement,const Element & subject);

        inline static bool isWordLeft();

        inline static bool isWordRight();
};

#endif // RULEMANAGER_H
