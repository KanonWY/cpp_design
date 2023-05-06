#ifndef __URL_CONTANCT_H__
#define __URL_CONTANCT_H__

namespace kanon
{

enum ApolloOp
{
    GET_ALL_NS,
    GET_ONE_NS,
    CR_NEW_NS,
    ADD_CFG,
    DEL_CFG,
    MOD_CFG,
    GET_CFG,
    PUB_NS
};

template <typename R, typename HTTP_SERVER, ApolloOp OP, typename... Args>
R execApolloOp(Args... args);

} // namespace kanon

#endif