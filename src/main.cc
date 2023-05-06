#include <iostream>
#include "policy/policy.h"
#include "policy/yaml_policy.h"

using namespace kanon;

int main01(int argc, char *argv[])
{
    BasePolicy<YamlPolicy> *sp = new YamlPolicy;
    std::map<std::string, std::string> m;
    m.insert({"koko", "lplp"});
    auto res = sp->dealWithAllPublicConfig(m);
    std::cout << "res = " << res << std::endl;

    std::string n;

    res = sp->dealWithAllPublicConfig(n);
    std::cout << "res = " << res << std::endl;
    return 0;
}